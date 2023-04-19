/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:53:49 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/19 10:36:04 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Main loop of the minishell parsing process.

Function responsibilities:

Check for unclosed quotes and set the state to PROMPTSTATE if true.
Check for only spaces and set the state to CLEANSTATE if true.
Insert extra spaces to the input string if needed.
Split the input string into individual words.
Set a token list of the splitted input string.
Expand variables in the input string.
Categorize tokens based on their type (command, argument, redirection, etc.).
Remove quotes from the tokenized input string.
Set the state to EXECSTATE, ready for execution.
*/
int	ft_minishell_parser(t_data *ms)
{
	if (ft_parser_quotes(ms))
	{
		ms->state = PROMPTSTATE;
		return (1);
	}
	if (ft_parser_onlyspc(ms->input))
	{
		ms->state = CLEANSTATE;
		ms->split = NULL;
		return (0);
	}
	ft_parser_spacer(ms);
	ft_parser_split(ms);
	ft_parser_tokenize(ms);
	ft_parser_expand(ms);
	ft_parser_categorize(ms->tokens);
	ft_parser_rmquotes(ms->tokens);
	ms->state = EXECSTATE;
	return (0);
}
