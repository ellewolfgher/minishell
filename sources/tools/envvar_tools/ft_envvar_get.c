/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:50:50 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/12 13:33:47 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Returns the value of the environment variable whose name is name.
char	*ft_envvar_get(t_env_vars *env_vars, const char *name)
{
	char		**split;
	char		*value;
	t_env_vars	*temp;

	if (!env_vars)
		return (NULL);
	temp = env_vars;
	while (temp)
	{
		split = ft_split(temp->content, '=');
		if (split && split[0] && ft_strcmp(split[0], name) == 0)
		{
			value = ft_strdup(split[1]);
			ft_free_matrix((void ***)&split);
			return (value);
		}
		ft_free_matrix((void ***)&split);
		temp = temp->next;
	}
	return (NULL);
}
