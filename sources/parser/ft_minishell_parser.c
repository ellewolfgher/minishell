/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:53:49 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/27 18:13:06 by ridalgo-         ###   ########.fr       */
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
		ms->state = CLEANSTATE;
		ms->split = NULL;
		ms->spaced = NULL;
		return (0);
	}
	ms->spaced = ft_parser_spacer(ms->input, ms);
	if (ms->inputnull)
		ms->input = NULL;
	ft_parser_split(ms);
	ft_parser_tokenize(ms);
	ms->state = EXECSTATE;
	return (0);
}
