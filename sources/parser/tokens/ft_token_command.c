/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:23:32 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/03 18:24:19 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Check if the token is a command
int	ft_token_command(t_tokens *temp)
{
	if (!temp->prev && !temp->next)
		return (1);
	if (!temp->prev)
		return (1);
	if (temp->prev && temp->prev->type == OPTOKEN)
		return (1);
	if (temp->prev && temp->prev->type == FDTOKEN)
	{
		if (temp->prev->prev && temp->prev->prev->type == REDTOKEN)
			return (1);
	}
	return (0);
}
