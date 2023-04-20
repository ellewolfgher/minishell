/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:53:49 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/20 16:46:17 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_get_tkerrors(t_data *ms)
{
	t_tokens	*aux;
	int			acs;

	aux = ms->tokens;
	while (aux)
	{
		if (aux->type == FDTOKEN)
		{
			acs = access(aux->value, F_OK);
			// printf("%s is file: %d\n", aux->value, acs);
			if (acs)
			{
				if (!ms->fd_error)
				{
					ft_putstr_fd("minishell: ", STDERR_FILENO);
					ft_putstr_fd(aux->value, STDERR_FILENO);
					ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
					ms->exit_code = 1;
					ms->fd_error = 1;
				}
			}
			acs = access(aux->value, W_OK);
			// printf("%s is writable: %d\n", aux->value, acs);
			if (acs)
			{
				if (!ms->fd_error)
				{
					ft_putstr_fd("minishell: ", STDERR_FILENO);
					ft_putstr_fd(aux->value, STDERR_FILENO);
					ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
					ms->exit_code = 1;
					ms->fd_error = 1;
				}
			}
		}
		aux = aux->next;
	}
}
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
	ft_get_tkerrors(ms);
	ms->state = EXECSTATE;
	return (0);
}
