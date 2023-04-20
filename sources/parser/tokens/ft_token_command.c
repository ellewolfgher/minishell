/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:23:32 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/20 11:09:29 by ewolfghe         ###   ########.fr       */
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
			return (0);
	}
	return (0);
}
