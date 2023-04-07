/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:39:55 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/07 18:46:17 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Create a new environment variable or update an existing one
void	ft_command_export(t_tokens *tokens, t_env_vars **envp)
{
	t_tokens	*curr_token;
	size_t		name_len;
	char		*env_value;
	char		*var_name;
	char		*equals_ptr;

	curr_token = tokens->next;
	while (curr_token)
	{
		if (curr_token->type == WORDTOKEN && ft_strchr(curr_token->value, '='))
		{
			equals_ptr = ft_strchr(curr_token->value, '=');
			name_len = equals_ptr - curr_token->value;
			var_name = ft_substr(curr_token->value, 0, name_len);
			env_value = ft_envvar_get(*envp, var_name);
			if (env_value)
				ft_free((void **)&(env_value));
			else
				ft_envvar_back(envp, ft_envvar_new(curr_token->value));
			env_value = ft_envvar_get(*envp, var_name);
			env_value = ft_strdup(curr_token->value);
			ft_free((void **)&var_name);
		}
		curr_token = curr_token->next;
	}
}
