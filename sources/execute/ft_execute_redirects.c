/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_redirects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:53:47 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/19 22:37:55 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 Redirects the standard input to a temporary file containing here-document
 content. Takes an array of original file descriptors, a pointer to a t_redirect
 struct, and a pointer to t_data struct as parameters. Returns 1 if an error
 occurs or 0 if the redirection is successful.

 Example: if in->target is "EOF" and ms has a here-document with content, the
 function redirects standard input to a temporary file containing that content.
*/
static int	ft_redir_heredoc(int og_fds[2], t_redirect *in, t_data *ms)
{
	char	*heredoc_file;
	int		fd;
	int		pipe_out;

	pipe_out = dup(STDOUT_FILENO);
	ft_fds_restore(og_fds);
	heredoc_file = ft_execute_heredoc(in->target, ms);
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

/*
 Redirects the standard input to a file. Takes a pointer to a t_redirect struct
 as a parameter. Returns 1 if the target file is not found or 0 if the input
 redirection is successful.

 Example: if in->target is "/path/to/input_file", the function redirects
 standard input to the specified file.
*/
static int	ft_redir_input(t_redirect *in)
{
	int	fd;

	if (in->target && access(in->target, F_OK))
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
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

/*
 Handles input redirection for a command. Takes a pointer to a t_redirect struct
 for input redirection, an array of original file descriptors, and a pointer to
 t_data struct as parameters. Returns 1 if an error occurs or 0 if input
 redirection is successful.

 Example: if red_in points to a list of input redirections and ms has environment
 and exit code data, the function handles all input redirections for the command.
*/
static int	ft_is_input(t_redirect *red_in, int og_fds[2], t_data *ms)
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
			if (ft_redir_input(in))
				return (1);
		if (in->type == HEREDOC)
			if (ft_redir_heredoc(og_fds, in, ms))
				return (1);
		in = in->next;
	}
	return (0);
}

/*
 Handles output redirection for a command. Takes a pointer to a t_redirect struct
 for output redirection and an array of original file descriptors as parameters.
 Returns 1 if an error occurs or 0 if output redirection is successful.

 Example: if red_out points to a list of output redirections, the function
 handles all output redirections for the command.
*/
static int	ft_is_output(t_redirect *red_out, int og_fds[2])
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

/*
Handles input and output redirection for a command. Takes a pointer to a
t_execute structure containing the command and its redirections, an array of
original file descriptors, and a pointer to the t_data structure containing the
shell data. Returns 1 if there is an error in input redirection, 0 otherwise.

Example: if the command structure represents "ls > output.txt" with
red_out containing the target "output.txt", the function redirects the
output of the "ls" command to the file "output.txt".
*/
int	ft_execute_redirects(t_execute *command, int og_fds[2], t_data *ms)
{
	if (ft_is_input(command->red_in, og_fds, ms))
		return (1);
	ft_is_output(command->red_out, og_fds);
	return (0);
}
