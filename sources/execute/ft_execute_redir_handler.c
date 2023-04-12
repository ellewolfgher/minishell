/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_redir_handler.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:53:47 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/12 20:07:42 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

int	ft_execute_redir_handler(t_execute *command, int og_fds[2], t_data *ms)
{
	if (handle_input(command->red_in, og_fds, ms))
		return (1);
	handle_output(command->red_out, og_fds);
	return (0);
}
