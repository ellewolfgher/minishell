/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:48:40 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/12 20:09:50 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Executes a built-in command, handling redirections, and setting the exit code
based on the executed built-in command.
*/
int	ft_execute_builtin(t_execute *command, t_data *ms, int og_fds[2])
{
	(void)og_fds;
	if (!command->sends_to_pipe && !command->receives_from_pipe)
	{
		// if (ft_execute_redir_handler(command, og_fds, ms))
		// 	return (ft_fds_restore(og_fds));
	}
	if (!ft_strcmp(command->command, "echo"))
		ft_command_echo(ms);
	if (!ft_strcmp(command->command, "cd"))
		ft_command_cd(ms);
	if (!ft_strcmp(command->command, "pwd"))
		ft_command_pwd();
	if (!ft_strcmp(command->command, "export"))
		ft_command_export(ms->tokens, &ms->env_vars);
	if (!ft_strcmp(command->command, "unset"))
		ft_command_unset(ms->tokens, &ms->env_vars);
	if (!ft_strcmp(command->command, "env"))
		ft_command_env(ms->env_vars);
	if (!ft_strcmp(command->command, "exit"))
		ft_command_exit(ms);
	return (0);
}
