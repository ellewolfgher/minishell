/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:00:23 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/20 21:14:59 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Executes a single command without pipes. If the command is a built-in command,
calls the built-in function. Otherwise, executes the command using
ft_execute_command. Stores the exit code in the t_data structure.

Example:
Assuming the command "ls -l" is executed, this function will run the command
and store the exit code in the t_data structure.
*/
static int	ft_execute_only_one(t_execute *command, t_data *ms, int og_fds[2])
{
	if (ms->need_to_exit)
		return (ms->need_to_exit);
	if (command->is_builtin)
		ft_execute_builtin(command, ms, og_fds);
	else
		ms->exit_code = ft_execute_command(command, ms, og_fds);
	return (0);
}

/*
Executes a command or a series of piped commands. If the command is blocked,
prints an error message. If the command is not part of a pipeline, calls
ft_execute_only_one. Otherwise, calls ft_execute_multiple. Returns an integer
indicating the status of the execution.

Example:
Assuming the command "ls -l | grep foo" is executed, this function will handle
the pipe between "ls -l" and "grep foo" and execute both commands in the
pipeline.
*/
int	ft_execute_loop(t_execute *command, t_data *ms, int og_fds[2])
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
		ft_execute_only_one(command, ms, og_fds);
		return (0);
	}
	else if (!ms->need_to_exit)
		return (ft_execute_multiple(command, ms, og_fds));
	return (1);
}
