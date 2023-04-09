/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_iterate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:34:15 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/09 17:39:28 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Iterate the list to the actual tok_index inside of the data struct
t_tokens	*ft_tokens_iterate(t_data *ms)
{
	t_tokens	*aux;

	aux = ms->tokens;
	while (aux && (aux->index != ms->tok_index))
		aux = aux->next;
	return (aux);
}
