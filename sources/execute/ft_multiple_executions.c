/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_executions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:15:05 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/21 21:31:56 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_setup_pipes_and_redirects(t_execute *command,
	t_data *ms, int og_fds[2], int *temp_fd)
{
	if (!ft_execute_get_error(command->command, ms))
	{
		ft_signals_default();
		if (command->red_in && ft_execute_redirects(command, og_fds, ms))
		{
			ms->need_to_exit = -1;
			return (ft_fds_restore(og_fds));
		}
		ft_handle_pipes(ms, command);
		if (command->sends_to_pipe && command->red_out)
		{
			*temp_fd = dup(STDOUT_FILENO);
			ft_execute_redirects(command, og_fds, ms);
		}
		return (0);
	}
	ms->need_to_exit = -1;
	return (1);
}

static void	ft_command(t_execute *command, int *temp_fd)
{
	execve(command->command, command->args, command->envp);
	if (*temp_fd != -1)
	{
		dup2(*temp_fd, STDOUT_FILENO);
		close(*temp_fd);
	}
}

static int	ft_handle_child_process(t_execute *command,
	t_data *ms, int og_fds[2])
{
	int	temp_fd;

	temp_fd = -1;
	ms->exit_code = 0;
	if (ft_setup_pipes_and_redirects(command, ms, og_fds, &temp_fd) == 0)
		ft_command(command, &temp_fd);
	return (ms->exit_code);
}

static void	ft_close_pipes(t_data *ms)
{
	close(ms->pipe_in[0]);
	close(ms->pipe_in[1]);
}

/*
Executes a command in a new process as part of a pipeline. Handles pipes, sets
signals, and calls the command. The exit code is stored in the t_data structure.

Example:
Assuming the command "ls -l | grep foo" is executed, this function will handle
the pipe between "ls -l" and "grep foo" and execute the command "grep foo".
*/
int	ft_multiple_executions(t_execute *command, t_data *ms, int og_fds[2])
{
	int	pid;

	pid = ft_execute_fork();
	if (!pid)
		return (ft_handle_child_process(command, ms, og_fds));
	ft_close_pipes(ms);
	return (ms->exit_code);
}
