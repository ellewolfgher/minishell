/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:54:06 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/14 18:08:44 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Executes the given command in a new process, sets the exit code in the t_data
structure, and returns the exit code as an integer. If the command is not valid
or not executable, sets an appropriate error code and prints an error message.

Example:
Imagine that the command is "ls -l /tmp" and that the command is valid and
executable. If the command is executed successfully, exit_code will store the
exit code.
*/
int	ft_execute_command(t_execute *command, t_data *ms, int og_fds[2])
{
	int	pid;

	(void)og_fds;
	pid = ft_execute_fork();
	if (!pid)
	{
		ms->exit_code = 0;
		if (!ft_execute_get_error(command->command, ms))
		{
			ft_signals_default();
			if (ft_execute_redirects(command, og_fds, ms))
			{
				ms->need_to_exit = -1;
				return (ft_fds_restore(og_fds));
			}
			execve(command->command, command->args, command->envp);
		}
		else
			ms->need_to_exit = -1;
		return (ms->exit_code);
	}
	return (ms->exit_code);
}
