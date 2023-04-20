/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_multiple.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:36:14 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/20 18:52:57 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Handles pipes for the current command. If the command receives input from a
pipe, closes the writing end of the input pipe and duplicates the reading end
to stdin.
If the command sends output to a pipe, closes the reading end of the output
pipe and duplicates the writing end to stdout.

Example:
Assuming the command "ls -l | grep foo" is executed, this function will handle
the pipe between "ls -l" and "grep foo", allowing data to be passed between them.
*/
static int ft_handle_pipes(t_data *ms, t_execute *command)
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
Executes a piped built-in command in a new process. Handles pipes, sets signals,
and calls the built-in function. The exit code is stored in the t_data structure

Example:
Assuming the command "echo foo | my_builtin" is executed, this function will
handle the pipe and execute the built-in command "my_builtin" in a new process.
*/
static int	ft_execute_piped_builtin(t_execute *command,
				t_data *ms, int og_fds[2])
{
	int	pid;

	pid = ft_execute_fork();
	if (!pid)
	{
		ft_signals_default();
		ft_handle_pipes(ms, command);
		if (ft_execute_redirects(command, og_fds, ms))
		{
			ms->need_to_exit = -1;
			return (ft_fds_restore(og_fds));
		}
		ms->need_to_exit = -1;
		ft_execute_builtin(command, ms, og_fds);
	}
	return (ms->exit_code);
}

/*
Executes a command in a new process as part of a pipeline. Handles pipes, sets
signals, and calls the command. The exit code is stored in the t_data structure.

Example:
Assuming the command "ls -l | grep foo" is executed, this function will handle
the pipe between "ls -l" and "grep foo" and execute the command "grep foo".
*/
static int ft_multiple_executions(t_execute *command, t_data *ms, int og_fds[2])
{
	int pid;

	pid = ft_execute_fork();
	if (!pid)
	{
		ms->exit_code = 0;
		if (!ft_execute_get_error(command->command, ms))
		{
			ft_signals_default();
			if (!command->receives_from_pipe && command->red_in && ft_execute_redirects(command, og_fds, ms))
			{
				ms->need_to_exit = -1;
				return (ft_fds_restore(og_fds));
			}

			ft_handle_pipes(ms, command);
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
Swaps pipe_in and pipe_out in the t_data structure and creates a new pipe_out.
This function is used to manage pipes in a pipeline of commands.

Example:
If the command "ls -l | grep foo | wc -l" is executed, this function will
manage the pipes between the commands, ensuring that data flows correctly.
*/
static int	ft_pipe_swap(t_data *ms)
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

/*
Executes a command as part of a pipeline, handling pipes and built-in commands.
Stores the exit code in the t_data structure and returns an integer indicating
whether the command sends output to a pipe.

Example:
Assuming the command "ls -l | grep foo" is executed, this function will handle
the pipe between "ls -l" and "grep foo", executing both commands in the pipeline.
*/
int	ft_execute_multiple(t_execute *command, t_data *ms, int og_fds[2])
{
	int	control;

	if (og_fds[0] == NO_REDIRECT)
		og_fds[0] = dup(STDIN_FILENO);
	if (og_fds[1] == NO_REDIRECT)
		og_fds[1] = dup(STDOUT_FILENO);
	ft_pipe_swap(ms);
	control = command->sends_to_pipe;
	if (ms->need_to_exit)
		return (ms->need_to_exit);
	if (command->is_builtin)
		ms->exit_code = ft_execute_piped_builtin(command, ms, og_fds);
	else
		ms->exit_code = ft_multiple_executions(command, ms, og_fds);
	return (control);
}
