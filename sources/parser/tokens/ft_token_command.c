/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:23:32 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/20 15:37:11 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Check if the token is a command
int	ft_token_command(t_tokens *aux)
{
	if (!aux->prev && !aux->next)
		return (1);
	if (!aux->prev)
		return (1);
	if (aux->prev && aux->prev->type == OPTOKEN)
		return (1);
	if (aux->prev && aux->prev->type == FDTOKEN)
	{
		if (aux->prev->prev && aux->prev->prev->type == REDTOKEN)
			return (0);
	}
	return (0);
}
