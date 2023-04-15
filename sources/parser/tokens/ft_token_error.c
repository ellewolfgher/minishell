/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:30:32 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/15 17:56:50 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Checks if no rules are broken, returns 1 if there is an error
int	ft_token_error(t_tokens *aux)
{
	if (aux->type == OPTOKEN && (!ft_strcmp(aux->value, "||")))
		return (1);
	if (aux->type == OPTOKEN && !aux->prev)
		return (1);
	if (aux->prev && aux->prev->type == REDTOKEN)
		if (aux->type == OPTOKEN || aux->type == REDTOKEN)
			return (1);
	if (aux->prev && aux->prev->type == OPTOKEN)
		if (aux->type == OPTOKEN)
			return (1);
	if ((aux->type == REDTOKEN || aux->type == OPTOKEN) && !aux->next)
		return (1);
	return (0);
}
