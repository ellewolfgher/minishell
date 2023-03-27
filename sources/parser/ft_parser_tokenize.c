/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_tokenize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:07:50 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/24 20:13:11 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tokens	*ft_parser_tokenize(t_data *ms)
{
	int			index;
	t_tokens	*self;
	t_tokens	*temp;
	t_tokens	*previous;

	if (!ms->split || !ms->split[0])
		return (NULL);
	index = 0;
	self = ft_calloc(1, sizeof(*self));
	temp = self;
	temp->prev = NULL;
	while (ms->split[index])
	{
		temp->value = ft_strdup(ms->split[index]);
		if (ms->split[index + 1])
			temp->next = ft_calloc(1, sizeof(*self));
		previous = temp;
		temp = temp->next;
		if (temp)
			temp->prev = previous;
		index++;
	}
	return (self);
}
