/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_redirects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:53:47 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/14 12:29:16 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_mouli(void *a, void *b)
{
	free(a);
	free(b);
	a = NULL;
	b = NULL;
}

char	*hd_update_exit_code(char *str, char *exit_code, char *var_head)
{
	char	*part1;
	char	*final_str;

	part1 = ft_strjoin(str, exit_code);
	final_str = ft_strjoin(part1, var_head + 2);
	free(part1);
	return (final_str);
}

char	*hd_expand_exit_code(t_ms_data *ms, char *str)
{
	char		*v_head;
	char		*exit_str;
	char		*temp;

	while (1)
	{
		v_head = find_exit_code(str);
		if (v_head)
		{
			*v_head = '\0';
			exit_str = ft_itoa(ms->exit_code);
			temp = str;
			str = hd_update_exit_code(str, exit_str, v_head);
			free_mouli(exit_str, temp);
		}
		else
			break ;
	}
	return (str);
}

char	*hd_update_str(char *str, char *var_name, char *var_head, t_ms_data *ms)
{
	char	*value;
	char	*part1;
	char	*final_str;
	void	*temp;

	temp = str;
	value = get_var_value(var_name, ms->env_head);
	if (!value)
		part1 = ft_strdup(str);
	else
		part1 = ft_strjoin(str, value);
	final_str = ft_strjoin(part1, var_head + 1 + ft_strlen(var_name));
	free(value);
	free(part1);
	free(temp);
	return (final_str);
}

char	*heredoc_handle_expansions(char *str, t_ms_data *ms)
{
	char	*var_head;
	char	*var_name;

	while (1)
	{
		var_head = find_variable(str);
		if (var_head)
		{
			var_name = get_var_name(var_head);
			*var_head = '\0';
			str = hd_update_str(str, var_name, var_head, ms);
			free(var_name);
		}
		else
			break ;
	}
	str = hd_expand_exit_code(ms, str);
	return (str);
}

static void	print_error(char *target, int line, int ret_fd)
{
	char	*linestr;

	linestr = ft_itoa(line);
	write(2, "bash: warning: here-document at line ", 37);
	write(2, linestr, ft_strlen(linestr));
	write(2, " delimited by end-of-file (wanted '", 35);
	write(2, target, ft_strlen(target));
	write(2, "')\n", 3);
	free (linestr);
	close (ret_fd);
}

int	write_to_heredoc(int ret_fd, char *target, t_ms_data *ms)
{
	int		i;
	char	*buffer;

	i = 2;
	while (1)
	{
		i++;
		buffer = readline(">");
		if (!buffer)
		{
			print_error(target, i, ret_fd);
			return (1);
		}
		buffer = heredoc_handle_expansions(buffer, ms);
		if (!ft_strcmp(buffer, target))
		{
			free(buffer);
			return (1);
		}
		write(ret_fd, buffer, ft_strlen(buffer));
		write(ret_fd, "\n", 1);
		free(buffer);
	}
	return (0);
}

static int	generate_a_random_name(char *random_name, char *seed)
{
	int		i;
	void	*ptr;

	i = ft_strlcpy(random_name, "/tmp/", PATH_MAX - 1);
	i += ft_strlcat(random_name, "msh", PATH_MAX - 1);
	i += ft_strlcat(random_name, seed, PATH_MAX - 1);
	ptr = malloc (1);
	if (!ptr)
		return (-1);
	free (ptr);
	ptr = ft_itoa((size_t) ptr);
	i += ft_strlcat(random_name, ptr, PATH_MAX - 1);
	free (ptr);
	if (i >= PATH_MAX)
	{
		write (2, "heredoc too big!\n", 17);
		return (-1);
	}
	return (i);
}

void	daddy_issues(int pid)
{
	int	i;

	if (pid)
	{
		ignore_signals();
		waitpid(pid, &i, 0);
		signal_handlers();
	}
}

char	*heredoc(char *target, t_ms_data *ms)
{
	int		ret_fd;
	int		pid;
	char	random_name[PATH_MAX];

	if (!target)
		return (0);
	generate_a_random_name(random_name, target);
	ret_fd = open (random_name, O_CREAT | O_TRUNC | O_DIRECTORY | O_RDWR, 0666);
	pid = fork();
	daddy_issues(pid);
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		write_to_heredoc(ret_fd, target, ms);
		close(ret_fd);
		ms->issue_exit = -1;
		return (0);
	}
	close(ret_fd);
	return (ft_strdup(random_name));
}

static int	redirect_input(t_redirect *in)
{
	int	fd;

	if (in->target && access(in->target, F_OK))
	{
		ft_putstr_fd(in->target, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		return (1);
	}
	else if (in->target)
	{
		fd = open(in->target, O_RDONLY, FD_CLOEXEC);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (0);
}

static int	redirect_heredoc(int og_fds[2], t_redirect *in, t_data *ms)
{
	char	*heredoc_file;
	int		fd;
	int		pipe_out;

	pipe_out = dup(STDOUT_FILENO);
	ft_fds_restore(og_fds);
	heredoc_file = heredoc(in->target, ms);
	if (!heredoc_file)
		return (1);
	fd = open(heredoc_file, O_RDONLY, FD_CLOEXEC);
	dup2(fd, STDIN_FILENO);
	close(fd);
	unlink(heredoc_file);
	free(heredoc_file);
	dup2(pipe_out, STDOUT_FILENO);
	return (0);
}

static int	handle_input(t_redirect *red_in, int og_fds[2], t_data *ms)
{
	t_redirect	*in;

	in = red_in;
	if (!in)
		return (0);
	if (og_fds[0] == NO_REDIRECT)
		og_fds[0] = dup(STDIN_FILENO);
	while (in)
	{
		if (in->type == INFILE)
			if (redirect_input(in))
				return (1);
		if (in->type == HEREDOC)
			if (redirect_heredoc(og_fds, in, ms))
				return (1);
		in = in->next;
	}
	return (0);
}

static int	handle_output(t_redirect *red_out, int og_fds[2])
{
	t_redirect	*out;
	int			fd;

	out = red_out;
	if (!out)
		return (0);
	if (og_fds[1] == NO_REDIRECT)
		og_fds[1] = dup(STDOUT_FILENO);
	while (out)
	{
		if (out->type == OVERWRITE)
			fd = open(out->target, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		else if (out->type == APPEND)
			fd = open(out->target, O_CREAT | O_WRONLY | O_APPEND, 0777);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		out = out->next;
	}
	return (0);
}

int	ft_execute_redirects(t_execute *command, int og_fds[2], t_data *ms)
{
	if (handle_input(command->red_in, og_fds, ms))
		return (1);
	handle_output(command->red_out, og_fds);
	return (0);
}
