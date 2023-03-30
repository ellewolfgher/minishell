/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:00:01 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 12:40:06 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Foward until quotes
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
static int	ft_wordlen(char *string)
{
	char	*aux;
	int		size;
	int		ret;

	aux = string;
	size = 0;
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
			ret ++;
		}
	}
	return (ret);
}

// Copy the string to the split
static void	ft_string_to_split(t_data *ms, char *string, int size, int index)
{
	int	k;

	k = 0;
	while (k < size)
	{
		ms->split[index][k] = *string;
		string++;
		k++;
	}
}

//Tokenize input string by whitespaces
void	ft_parser_split(t_data *ms)
{
	char	*string;
	int		words;
	int		index;
	int		size;

	string = ms->input;
	index = 0;
	size = 0;
	words = ft_count_words(string);
	ms->split = ft_calloc ((words + 1), sizeof(char *));
	while (index < words)
	{
		while (*string == ' ')
			string++;
		size = (ft_wordlen(string));
		ms->split[index] = ft_calloc (size + 1, 1);
		ft_string_to_split (ms, string, size, index);
		string += size;
		index++;
	}
	ms->split[index] = NULL;
}
