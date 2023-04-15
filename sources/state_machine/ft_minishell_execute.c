/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_execute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:21 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/15 18:41:29 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Main loop of the minishell execution.

Function responsibilities:

Ignore signals during command execution.
Execute the main loop of the minishell, iterating through commands.
Process signals.
Handle exit codes.
Reinitialize signals and restore file descriptors.
Set the state to CLEANSTATE.
*/
int	ft_minishell_execute(t_data *ms)
{
	t_execute	*command;
	int			control;
	int			og_fds[2];

	control = 1;
	og_fds[0] = -1;
	og_fds[1] = -1;
	ft_signals_ignore();
	while (control)
	{
		command = ft_execute_set_commands(ms);
		control = ft_execute_loop(command, ms, og_fds);
		ft_free_execute(command);
		if (ms->need_to_exit)
			break ;
	}
	while (wait(&ms->exit_code) > 0)
		continue ;
	if (ms->exit_code >= 256)
		ms->exit_code = ms->exit_code >> 8;
	ft_signals_init();
	ft_fds_restore(og_fds);
	ms->state = CLEANSTATE;
	return (0);
}
