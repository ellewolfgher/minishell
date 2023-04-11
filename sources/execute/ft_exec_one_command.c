/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_one_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:25:54 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/11 05:17:05 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Execute the command
void	ft_exec_one_command(t_data *ms)
{
	if (strcmp(ms->tokens->value, "cd") == 0)
		ft_command_cd(ms);
	else if (strcmp(ms->tokens->value, "pwd") == 0)
		ft_command_pwd();
	else if (strcmp(ms->tokens->value, "exit") == 0)
		ft_command_exit(ms);
	else if (strcmp(ms->tokens->value, "export") == 0)
		ft_command_export(ms->tokens, &(ms->env_vars));
	else if (strcmp(ms->tokens->value, "unset") == 0)
		ft_command_unset(ms->tokens, &(ms->env_vars));
	else if (strcmp(ms->tokens->value, "env") == 0)
		ft_command_env(ms->env_vars);
	else if (strcmp(ms->tokens->value, "echo") == 0)
		ft_command_echo(ms);
	if (ms->state == EXITSTATE)
		ms->state = EXITSTATE;
	else
		ms->state = CLEANSTATE;
	return ;
}
