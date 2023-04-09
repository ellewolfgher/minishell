/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:08:34 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/09 18:11:22 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_redirect	*ft_redirect_list(int nodes)
{
	t_redirect	*head;
	t_redirect	*self;
	int			index;

	index = 0;
	if (!nodes)
		return (NULL);
	head = ft_calloc(1, sizeof(t_redirect));
	self = head;
	while (index < nodes - 1)
	{
		self->next = ft_calloc(1, sizeof(t_redirect));
		index++;
		self = self->next;
	}
	return (head);
}
