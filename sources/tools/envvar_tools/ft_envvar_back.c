/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:50:28 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/07 18:49:50 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Returns the last element of the list.
static t_env_vars	*ft_envvar_last(t_env_vars *element)
{
	if (element == NULL)
		return (NULL);
	while (element->next != NULL)
		element = element->next;
	return (element);
}

//Adds the element ’new’ at the end of the list.
void	ft_envvar_back(t_env_vars **stack, t_env_vars *new)
{
	t_env_vars	*last;

	if (!stack || !new)
		return ;
	last = ft_envvar_last(*stack);
	if (last != NULL)
		last->next = new;
	else
		*stack = new;
}
