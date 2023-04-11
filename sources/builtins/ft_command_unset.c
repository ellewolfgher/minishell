/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:30:51 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/11 05:15:45 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Remove the variable from the environment
void	ft_command_unset(t_tokens *tokens, t_env_vars **envp)
{
	t_tokens	*curr_token;
	char		*var_name;

	curr_token = tokens->next;
	while (curr_token)
	{
		if (curr_token->type == WORDTOKEN)
		{
			var_name = curr_token->value;
			ft_envvar_del(envp, var_name);
		}
		curr_token = curr_token->next;
	}
}
