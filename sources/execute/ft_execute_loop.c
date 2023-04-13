/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:00:23 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/13 10:46:02 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Forks the process and returns the child process ID. Exits with an error message
if forking fails.
*/
static pid_t	ft_pipex_is_easy(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		write(2, "error: couldn't fork the process\n", 34);
		exit(-1);
	}
	return (pid);
}

/*
Checks if a given path is executable, a directory, or nonexistent, and sets the
appropriate exit code in the t_data structure.
*/
int	get_exec_error(char *path, t_data *ms)
{
	struct stat	sb;

	if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		ms->exit_code = 126;
		printf("Is a directory!\n");
	}
	if (!path)
		ms->exit_code = 1;
	else if (access(path, X_OK))
	{
		ms->exit_code = 127;
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": command not found!\n", STDERR_FILENO);
	}
	return (ms->exit_code);
}

/*
Handles the input and output of a command with pipes by updating the standard
input and output file descriptors.
*/
int	pipe_handle(t_data *ms, t_execute *command)
{
	if (command->receives_from_pipe)
	{
		close(ms->pipe_in[1]);
		dup2(ms->pipe_in[0], STDIN_FILENO);
	}
	if (command->sends_to_pipe)
	{
		close(ms->pipe_out[0]);
		dup2(ms->pipe_out[1], STDOUT_FILENO);
	}
	return (0);
}

/*
Executes a built-in command in a forked child process, handling signals,
redirections, and restoring file descriptors.
*/
int	exec_fork_builtin(t_execute *command, t_data *ms, int og_fds[2])
{
	int	pid;

	pid = ft_pipex_is_easy();
	if (!pid)
	{
		ft_signals_default();
		pipe_handle(ms, command);
		// if (ft_execute_redirects(command, og_fds, ms))
		// {
		// 	ms->need_to_exit = -1;
		// 	return (ft_fds_restore(og_fds));
		// }
		ms->need_to_exit = -1;
		ft_execute_builtin(command, ms, og_fds);
	}
	return (ms->exit_code);
}

/*
Executes a single command in a forked child process, handling signals,
redirections, and setting the exit code.
*/
int	exec_com(t_execute *command, t_data *ms, int og_fds[2])
{
	int	pid;

	(void)og_fds;
	pid = ft_pipex_is_easy();
	if (!pid)
	{
		ms->exit_code = 0;
		if (!get_exec_error(command->command, ms))
		{
			ft_signals_default();
			// if (ft_execute_redirects(command, og_fds, ms))
			// {
			// 	ms->need_to_exit = -1;
			// 	return (ft_fds_restore(og_fds));
			// }
			execve(command->command, command->args, command->envp);
		}
		else
			ms->need_to_exit = -1;
		return (ms->exit_code);
	}
	return (ms->exit_code);
}

/*
Executes a single command in a forked child process for a command that is part
of a pipeline, handling signals, redirections, and setting the exit code.
*/
int	exec_com_multi(t_execute *command, t_data *ms, int og_fds[2])
{
	int	pid;

	(void)og_fds;
	pid = ft_pipex_is_easy();
	if (!pid)
	{
		ms->exit_code = 0;
		if (!get_exec_error(command->command, ms))
		{
			ft_signals_default();
			pipe_handle(ms, command);
			// if (ft_execute_redirects(command, og_fds, ms))
			// {
			// 	ms->need_to_exit = -1;
			// 	return (ft_fds_restore(og_fds));
			// }
			execve(command->command, command->args, command->envp);
		}
		else
			ms->need_to_exit = -1;
		return (ms->exit_code);
	}
	close(ms->pipe_in[0]);
	close(ms->pipe_in[1]);
	return (ms->exit_code);
}

/*
Checks if the given token list contains a pipe ("|") token.
*/
int	has_pipe(t_tokens *tokens)
{
	t_tokens	*head;

	head = tokens;
	while (head)
	{
		if (head->type == OPTOKEN && !ft_strcmp(head->value, "|"))
			return (1);
		head = head->next;
	}
	return (0);
}

/*
Executes a single t_execute command that is not part of a pipeline, handling
redirections, and setting the exit code.
*/
int	ft_execute_only_one(t_execute *command, t_data *ms, int og_fds[2])
{
	if (ms->need_to_exit)
		return (ms->need_to_exit);
	if (command->is_builtin)
		ft_execute_builtin(command, ms, og_fds);
	else
		ms->exit_code = exec_com(command, ms, og_fds);
	return (0);
}

int	swap_pipes(t_data *ms)
{
	static int	init;

	if (!init)
	{
		pipe(ms->pipe_out);
		init++;
	}
	ms->pipe_in[0] = ms->pipe_out[0];
	ms->pipe_in[1] = ms->pipe_out[1];
	pipe(ms->pipe_out);
	return (0);
}

int	exec_multi(t_execute *command, t_data *ms, int original_fds[2])
{
	int	control;

	if (original_fds[0] == NO_REDIRECT)
		original_fds[0] = dup(STDIN_FILENO);
	if (original_fds[1] == NO_REDIRECT)
		original_fds[1] = dup(STDOUT_FILENO);
	swap_pipes(ms);
	control = command->sends_to_pipe;
	if (ms->need_to_exit)
		return (ms->need_to_exit);
	if (command->is_builtin)
		ms->exit_code = exec_fork_builtin(command, ms, original_fds);
	else
		ms->exit_code = exec_com_multi(command, ms, original_fds);
	return (control);
}

/*
Executes a single t_execute command within a loop, handling pipelines,
redirections, and setting the exit code.
*/
int	ft_execute_loop(t_execute *command, t_data *ms, int ogfds[2])
{
	if (!command)
		return (0);
	if (command->block_exec)
	{
		write (2, command->error_to_print, ft_strlen(command->error_to_print));
		return (0);
	}
	ft_execute_output_create(command);
	if (!command->receives_from_pipe && !command->sends_to_pipe)
	{
		ft_execute_only_one(command, ms, ogfds);
		return (0);
	}
	else if (!ms->need_to_exit)
		return (exec_multi(command, ms, ogfds));
	return (1);
}
