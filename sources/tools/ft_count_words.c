/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:04:23 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/27 15:43:44 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Skips quotes
static void	ft_foward_quotes(char *temp)
{
	char	first;

	first = *temp;
	if (first == '\'' || first == '\"')
	{
		if (temp[1])
			temp++;
		while (*temp && (*temp != first))
			temp++;
		if (*temp == first)
			temp++;
	}
}

// Counts words in string
int	ft_count_words(char *string)
{
	int		words;
	char	*temp;

	words = 0;
	temp = ft_strdup(string);
	while (*temp)
	{
		words++;
		while (*temp == ' ')
			temp++;
		while (*temp && (*temp != ' '))
		{
			if (*temp == '\'' || *temp == '\"')
				ft_foward_quotes(temp);
			else
				temp++;
		}
	}
	return (words);
}
