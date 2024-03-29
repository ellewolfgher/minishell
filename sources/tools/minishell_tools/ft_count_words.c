/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:04:23 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/06 11:38:44 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Skips quotes
static int	ft_foward_quotes(char *string)
{
	char	first;
	int		index;

	index = 0;
	first = string[index];
	if (first == '\'' || first == '\"')
	{
		index++;
		while (string[index] && (string[index] != first))
			index++;
		if (string[index] == first)
			index++;
	}
	return (index);
}

// Counts words in string
int	ft_count_words(char *string)
{
	int		words;
	int		index;

	words = 0;
	index = 0;
	while (string[index])
	{
		words++;
		while (string[index] == ' ')
			index++;
		while (string[index] && (string[index] != ' '))
		{
			if (string[index] == '\'' || string[index] == '\"')
				index += ft_foward_quotes(&string[index]);
			else
				index++;
		}
	}
	return (words);
}
