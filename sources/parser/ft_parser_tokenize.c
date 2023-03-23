/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_tokenize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:00:01 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/23 18:17:08 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// // End current token, deals with escapes
// static void	double_commas(t_parsing *parsing, t_parsing_index *i)
// {
// 	if (i->current_token_index > 0)
// 	{
// 		parsing->current_token[i->current_token_index] = '\0';
// 		if (parsing->in_quotes)
// 		{
// 			parsing->tokens[i->t_index] = parsing->current_token + 1;
// 			parsing->current_token[i->current_token_index - 2] = '\0';
// 		}
// 		else
// 			parsing->tokens[i->t_index] = parsing->current_token;
// 		i->t_index++;
// 		parsing->current_token = (char *)malloc(MAX_TOKEN_LEN * sizeof(char));
// 		i->current_token_index = 0;
// 	}
// 	return ;
// }

// // Adds character to current token
// static void	add_char(t_parsing *parsing, t_parsing_index *i)
// {
// 	if (i->charac != '"' || !parsing->in_quotes)
// 	{
// 		parsing->current_token[i->current_token_index] = i->charac;
// 		i->current_token_index++;
// 	}
// 	return ;
// }

// // Adds last token to token list
// static void	last_token(t_parsing *parsing, t_parsing_index *i)
// {
// 	if (i->current_token_index > 0)
// 	{
// 		parsing->current_token[i->current_token_index] = '\0';
// 		parsing->tokens[i->t_index] = parsing->current_token;
// 		i->t_index++;
// 	}
// 	return ;
// }

// char	**ft_parser_tokenize(char *input)
// {
// 	t_parsing		*parsing;
// 	t_parsing_index	*i;

// 	i = ft_calloc(1, sizeof(t_parsing_index));
// 	parsing = ft_calloc(1, sizeof(t_parsing));
// 	parsing->tokens = (char **)malloc(MAX_TOKENS * sizeof(char *));
// 	parsing->current_token = (char *)malloc(MAX_TOKEN_LEN * sizeof(char));
// 	while (i->index < (int)strlen(input))
// 	{
// 		i->charac = input[i->index];
// 		if (i->charac == '"')
// 			parsing->in_quotes = !parsing->in_quotes;
// 		else if (i->charac == ' ' && !parsing->in_quotes)
// 			double_commas(parsing, i);
// 		else
// 			add_char(parsing, i);
// 		i->index++;
// 	}
// 	last_token(parsing, i);
// 	parsing->tokens[i->t_index] = NULL;
// 	free(i);
// 	return (parsing->tokens);
// }

//Count tokens in input string by whitespaces
//Returns an int with the number of tokens
static int	ft_count_tokens(char *input, int lenght)
{
	int	index;
	int	token_count;
	int	in_token;

	token_count = 0;
	in_token = 0;
	index = 0;
	while (index < lenght)
	{
		if (ft_is_whitespace(input[index]))
		{
			input[index] = '\0';
			in_token = 0;
		}
		else
		{
			if (!in_token)
				token_count += 1;
			in_token = 1;
		}
		index++;
	}
	return (token_count);
}

//Tokenize input string by whitespaces
void	ft_parser_tokenize(t_data *ms)
{
	int		lenght;
	int		in_token;
	int		token_index;
	int		index;

	lenght = strlen(ms->spaced);
	in_token = 0;
	token_index = 0;
	ms->tokens = malloc((ft_count_tokens(ms->spaced, lenght)) * sizeof(char *));
	index = 0;
	while (index < lenght)
	{
		if (ms->spaced[index] != '\0')
		{
			if (!in_token)
			{
				ms->tokens[token_index] = &ms->spaced[index];
				token_index++;
			}
			in_token = 1;
		}
		else
			in_token = 0;
		index++;
	}
}
