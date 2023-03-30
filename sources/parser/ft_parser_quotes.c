/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:09:48 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 11:21:58 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_parser_quotes(t_data *ms)
{
	int	control;
	int	singular;
	int	twins;

	control = 0;
	singular = 0;
	twins = 0;
	while (ms->input[control])
	{
		if (ms->input[control] == '\'' && (twins % 2 == 0))
			singular++;
		if (ms->input[control] == '\"' && (singular % 2 == 0))
			twins++;
		control++;
	}
	control = ((singular % 2) + (twins % 2));
	if (control)
	{
		ft_free(ms->input);
		ms->exit_code = 2;
		ms->state = PROMPTSTATE;
		printf ("Please close any open quotes\n");
		return (1);
	}
	return (0);
}