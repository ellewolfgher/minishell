/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_add_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:58:31 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/30 12:29:54 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env_add_var(t_env_vars **env_vars, char *env_var)
{
	char		**split;
	char		*key;
	char		*value;
	t_env_vars	*temp;

	split = ft_split(env_var, '=');
	key = split[0];
	value = split[1];
	temp = *env_vars;
	while (temp)
	{
		if (ft_strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = value;
			ft_free_split(split);
			return ;
		}
		temp = temp->next;
	}
	temp = ft_env_var_new(key, value);
	ft_env_back_add(env_vars, temp);
	ft_free_split(split);
}
