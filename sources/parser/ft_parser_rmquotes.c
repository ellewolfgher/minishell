/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_rmquotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:00:41 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/06 11:49:19 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Copies the string without the "quotes" that were transformed into a special
//character.
static void	ft_quotedcopy(char *value, char *temp, char one)
{
	while (*value)
	{
		if (*value == one)
		{
			value++;
			continue ;
		}
		*temp = *value;
		value++;
		temp++;
	}
}

//Counts the size of the word regarding the "quotes" that were
//transformed into a special character.
static int	ft_quotedsize(char *value, char one)
{
	int	size;

	size = 0;
	while (*value)
	{
		if (*value == one)
		{
			value++;
			continue ;
		}
		value++;
		size++;
	}
	return (size);
}

//Allocates memory and copies the string without the quotes.
static char	*ft_unquoted(char *value, char quote)
{
	char	*new_value;

	new_value = ft_calloc(ft_quotedsize(value, quote) + 1, sizeof(char));
	ft_quotedcopy(value, new_value, quote);
	return (new_value);
}

//Transforms quotes into a special character, so they can be removed later.
static void	ft_quote_to_one(char *value)
{
	char	singular;
	char	twins;

	singular = 0;
	twins = 0;
	while (*value)
	{
		if (*value == '\"' && !twins)
		{
			singular = (singular + 1) % 2;
			*value = 1;
		}
		if (*value == '\'' && !singular)
		{
			twins = (twins + 1) % 2;
			*value = 1;
		}
		value++;
	}
}

// Removes quotes from tokens, if any.
void	ft_parser_rmquotes(t_tokens *tokens)
{
	t_tokens	*aux_tokens;
	char		*unquoted_str;

	aux_tokens = tokens;
	while (aux_tokens)
	{
		ft_quote_to_one(aux_tokens->value);
		unquoted_str = ft_unquoted(aux_tokens->value, 1);
		ft_free((void **)&aux_tokens->value);
		aux_tokens->value = unquoted_str;
		aux_tokens = aux_tokens->next;
	}
}
