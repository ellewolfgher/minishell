/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:36:06 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/21 04:23:40 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 Prints an error message for a missing here-document delimiter. Takes the target
 delimiter, the line number where the delimiter was expected, and the file
 descriptor to close as parameters. No return value.

 Example: if target is "EOF", line is 42, it prints the following error message:
 "bash: warning: here-document at line 42 delimited by end-of-file
 (wanted 'EOF')"
 and closes the openedfd file descriptor.
*/
static void	ft_heredoc_error(char *target, int line, int openedfd)
{
	char	*str;

	str = ft_itoa(line);
	write(2, "bash: warning: here-document at line ", 37);
	write(2, str, ft_strlen(str));
	write(2, " delimited by end-of-file (wanted '", 35);
	write(2, target, ft_strlen(target));
	write(2, "')\n", 3);
	ft_free((void **)&str);
	if (openedfd != -1)
		close(openedfd);
}

/*
 Writes the contents of a here-document to a file descriptor. Takes the file
 descriptor to write to, the target delimiter, and a pointer to t_data struct
 containing environment variables and exit codes as parameters. Returns 1 when
 the target delimiter is found or an error occurs, 0 otherwise.

 Example: if target is "EOF", it writes the contents of the here-document to
 the openedfd file descriptor until the "EOF" delimiter is found.
*/
static int	ft_write_into(int openedfd, char *target, t_data *ms)
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
			ft_heredoc_error(target, i, openedfd);
			return (1);
		}
		buffer = ft_execute_heredoc_expansions(buffer, ms);
		if (!ft_strcmp(buffer, target))
		{
			ft_free((void **)&buffer);
			return (1);
		}
		write(openedfd, buffer, ft_strlen(buffer));
		write(openedfd, "\n", 1);
		ft_free((void **)&buffer);
	}
	return (0);
}

/*
 Generates a random file name using a seed and stores it in the provided
 random_name buffer. Returns the length of the generated file name or -1 if
 the file name is too big.

 Example: if seed is "EOF", the function generates a random file name like
 "/tmp/mshEOF12345" and stores it in the random_name buffer.
*/
static int	ft_filename_generator(char *random_name, char *seed)
{
	int		index;
	void	*ptr;

	index = ft_strlcpy(random_name, "/tmp/", PATH_MAX - 1);
	index += ft_strlcat(random_name, "msh", PATH_MAX - 1);
	index += ft_strlcat(random_name, seed, PATH_MAX - 1);
	ptr = malloc (1);
	if (!ptr)
		return (-1);
	ft_free((void **)&ptr);
	ptr = ft_itoa((size_t) ptr);
	index += ft_strlcat(random_name, ptr, PATH_MAX - 1);
	ft_free((void **)&ptr);
	if (index >= PATH_MAX)
	{
		write (2, "heredoc too big!\n", 17);
		return (-1);
	}
	return (index);
}

/*
 Handles parent process's behavior for dealing with child process. Takes the
 child process's ID (pid) as a parameter. If pid is non-zero, ignores signals,
 waits for the child process to finish, and restores the signal handlers.
*/
static void	ft_wait_ignoring_signals(int pid)
{
	int	why;

	if (pid)
	{
		ft_signals_ignore();
		waitpid(pid, &why, 0);
		ft_signals_init();
	}
}

/*
 Creates a temporary file containing the content of a here-document. Takes the
 target delimiter and a pointer to t_data struct as parameters. Returns the path
 to the temporary file containing the here-document content.

 Example: if target is "EOF", the function creates a temporary file with
 here-document content and returns the path to that file.
*/
char	*ft_execute_heredoc(char *target, t_data *ms)
{
	int		openedfd;
	int		pid;
	char	random_name[PATH_MAX];

	if (!target)
		return (0);
	ft_filename_generator(random_name, target);
	openedfd = open (random_name, O_CREAT | O_TRUNC
			| O_DIRECTORY | O_RDWR, 0666);
	pid = fork();
	ft_wait_ignoring_signals(pid);
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		ft_write_into(openedfd, target, ms);
		if (openedfd != -1)
			close(openedfd);
		ms->need_to_exit = -1;
		return (0);
	}
	if (openedfd != -1)
		close(openedfd);
	return (ft_strdup(random_name));
}
