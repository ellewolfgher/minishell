/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:00:01 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/03 18:43:41 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Foward the index until the end of the quotes
static int	ft_foward_until_quotes(char *string)
{
	char	quote;
	int		count;

	count = 0;
	quote = string[0];
	while (string[count] && (string[count] != quote || !count))
		count++;
	if (string[count] == quote)
		count++;
	return (count);
}

// Counts the size of the word regarding the quotes
static int	ft_wordlen(char *string, int index)
{
	char	*aux;
	int		size;
	int		ret;

	aux = string + index;
	ret = 0;
	while (*aux && *aux == ' ')
		aux++;
	while (*aux && *aux != ' ')
	{
		if (*aux == '\'' || *aux == '\"')
		{
			size = ft_foward_until_quotes(aux);
			aux += size;
			ret += size;
		}
		else
		{
			aux++;
			ret++;
		}
	}
	return (ret);
}

// Copy the string to the split
static int	ft_string_to_split(t_data *ms, int index, int size, int count)
{
	int	k;

	k = 0;
	while (k < size)
	{
		ms->split[count][k] = ms->input[index];
		index++;
		k++;
	}
	return (index);
}

//Tokenize input string by whitespaces
void	ft_parser_split(t_data *ms)
{
	int		words;
	int		index;
	int		size;
	int		count;

	index = 0;
	size = 0;
	count = 0;
	words = ft_count_words(ms->input);
	ms->split = ft_calloc ((words + 1), sizeof(char *));
	while (count < words)
	{
		while (ms->input[index] == ' ')
			index++;
		size = (ft_wordlen(ms->input, index));
		ms->split[count] = ft_calloc (size + 1, 1);
		index = ft_string_to_split(ms, index, size, count);
		count++;
	}
	ms->split[count] = NULL;
}
