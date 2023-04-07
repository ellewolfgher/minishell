/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:50:50 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/06 22:13:17 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_envvar_get(t_env_vars *env_vars, const char *name)
{
	char		**split;
	char		*key;
	char		*value;
	t_env_vars	*temp;

	if (!env_vars)
		return (NULL);
	temp = env_vars;
	while (temp)
	{
		split = ft_split(temp->content, '=');
		key = split[0];
		if (ft_strcmp(key, name) == 0)
		{
			value = split[1];
			ft_free_matrix((void ***)&split);
			return (value);
		}
		ft_free_matrix((void ***)&split);
		temp = temp->next;
	}
	return (NULL);
}
