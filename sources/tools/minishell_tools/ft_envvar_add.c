/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:58:31 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/07 18:49:37 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Add an environment variable to the list
void	ft_envvar_add(t_env_vars **env_vars, char *env_var)
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
		if (ft_strcmp(temp->content, key) == 0)
		{
			free(temp->content);
			temp->content = value;
			ft_free_matrix((void ***)&split);
			return ;
		}
		temp = temp->next;
	}
	ft_envvar_back(env_vars, ft_envvar_new(value));
	ft_free_matrix((void ***)&split);
}
