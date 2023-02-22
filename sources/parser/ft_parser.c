/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:00:01 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/02/20 18:49:18 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_parser(char *input)
{
	t_parsing	*parsing;
	int			i;
	char		c;
	char		**tokens;
	char		*current_token;

	i = 0;
	parsing = ft_calloc(1, sizeof(t_parsing));
	tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
	current_token = (char *)malloc(MAX_TOKEN_LEN * sizeof(char));
	while (i < (int)strlen(input))
	{
		c = input[i];
		if (c == '"')
			parsing->in_quotes = !parsing->in_quotes;
		else if (c == ' ' && !parsing->in_quotes)
		{
			// End of current token
			if (parsing->current_token_index > 0)
			{
				current_token[parsing->current_token_index] = '\0';
				tokens[parsing->token_index] = current_token;
				parsing->token_index++;
				current_token = (char *)malloc(MAX_TOKEN_LEN * sizeof(char));
				parsing->current_token_index = 0;
			}
		}
		else
		{
			// Add character to current token
			current_token[parsing->current_token_index] = c;
			parsing->current_token_index++;
		}
		i++;
	}
	// Add last token to token list
	if (parsing->current_token_index > 0)
	{
		current_token[parsing->current_token_index] = '\0';
		tokens[parsing->token_index] = current_token;
		parsing->token_index++;
	}
	// Add NULL as last token to indicate end of token list
	tokens[parsing->token_index] = NULL;
	return (tokens);
}
