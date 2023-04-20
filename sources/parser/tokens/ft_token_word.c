/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:25:44 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/20 15:37:25 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Checks if the value only contains printable characters
static int	ft_check_nonprintable(char *value)
{
	int	index;

	index = 0;
	while (value[index])
	{
		if (!ft_isprint(value[index]) && (value[index] != 0))
			return (0);
		index++;
	}
	return (1);
}

//Check if the token is a word
int	ft_token_word(t_tokens *aux)
{
	if (aux->value[0] == '\'' || aux->value[0] == '\"')
		return (1);
	if (ft_check_nonprintable(aux->value))
		return (1);
	return (0);
}
