/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:25:54 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/07 18:50:04 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Deletes the element whose name is var_name.
void	ft_envvar_del(t_env_vars **stack, char *var_name)
{
	t_env_vars	*prev;
	t_env_vars	*curr;

	prev = NULL;
	curr = *stack;
	while (curr)
	{
		if (ft_strncmp(curr->content, var_name, ft_strlen(var_name)) == 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				*stack = curr->next;
			ft_free_var(&curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
