/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:50:28 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 16:54:06 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
