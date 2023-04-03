/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:30:32 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/03 18:46:57 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Checks if no rules are broken, returns 1 if there is an error
int	ft_token_error(t_tokens *temp)
{
	if (temp->type == OPTOKEN && (!ft_strcmp(temp->value, "||")))
		return (1);
	if (temp->type == OPTOKEN && !temp->prev)
		return (1);
	if (temp->prev && temp->prev->type == REDTOKEN)
		if (temp->type == OPTOKEN || temp->type == REDTOKEN)
			return (1);
	if (temp->prev && temp->prev->type == OPTOKEN)
		if (temp->type == OPTOKEN)
			return (1);
	if ((temp->type == REDTOKEN || temp->type == OPTOKEN) && !temp->next)
		return (1);
	return (0);
}
