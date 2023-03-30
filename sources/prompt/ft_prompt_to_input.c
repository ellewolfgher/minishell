/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_to_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:32:48 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 12:10:02 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Stores the result from readline in ms->input
//Returns 0 on sucess, 1 on error.
int	ft_prompt_to_input(t_data *ms)
{
	char	*temporary;

	ms->input = readline(ms->prompt);
	if (ms->input)
	{
		temporary = ms->input;
		ms->input = ft_strtrim(temporary, " ");
		ft_free((void **)&(temporary));
		return (0);
	}
	else if (!(ms->input))
		return (1);
	return (0);
}
