/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_add_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:58:31 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/04 09:26:51 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
		if (ft_strcmp(temp->content, key) == 0)
		{
			free(temp->content);
			temp->content = value;
			ft_free_split(split);
			return ;
		}
		temp = temp->next;
	}
	temp = ft_env_var_new(value);
	ft_env_back_add(env_vars, temp);
	ft_free_split(split);
}
