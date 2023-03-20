/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:53:49 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/20 16:49:25 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Parse the input and check for errors
//If there are no errors, the input is split into tokens
int	ft_minishell_parser(t_data *ms)
{
	if (ft_parser_quotes(ms))
		return (1);
	if (ft_parser_onlyspc(ms->input))
	{
		// ms->rl_spaced_buffer = NULL;
		// ms->rl_split = NULL;
		ms->state = CLEANSTATE;
		return (0);
	}
	ms->tokens = ft_parser_tokenize(ms->input);
	ft_print_tokens(ms->tokens);
	ms->state = PROMPTSTATE;
	return (0);
}
