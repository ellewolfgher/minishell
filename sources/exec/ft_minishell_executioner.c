/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_executioner.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:21 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/27 18:19:43 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_minishell_executioner(t_data *ms)
{
	ft_print_tokens(ms->tokens);
	if (strcmp(ms->tokens->value, "cd") == 0)
		ft_command_cd(&(ms->tokens->value));
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
		ft_command_echo(&(ms->tokens->value));
	ms->state = PROMPTSTATE;
	return ;
}
