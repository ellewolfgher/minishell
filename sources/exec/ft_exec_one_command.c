/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_one_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:25:54 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/04 18:55:03 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exec_one_command(t_data *ms)
{
	ft_print_tokens(ms->tokens);
	if (strcmp(ms->tokens->value, "cd") == 0)
		ft_command_cd(ms);
	else if (strcmp(ms->tokens->value, "pwd") == 0)
		ft_command_pwd();
	else if (strcmp(ms->tokens->value, "exit") == 0)
		exit(0);
	else if (strcmp(ms->tokens->value, "export") == 0)
		ft_command_export();
	else if (strcmp(ms->tokens->value, "unset") == 0)
		ft_command_unset(&(ms->tokens->value));
	else if (strcmp(ms->tokens->value, "env") == 0)
		ft_command_env(&(ms->tokens->value));
	else if (strcmp(ms->tokens->value, "echo") == 0)
		ft_command_echo(ms);
	ms->state = CLEANSTATE;
	return ;
}
