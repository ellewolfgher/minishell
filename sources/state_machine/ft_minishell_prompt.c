/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_prompt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:53:28 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/13 10:51:10 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Stores the result from readline in ms->input
//Returns 0 on sucess, 1 on error.
static int	ft_prompt_to_input(t_data *ms)
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

//Stablishes the prompt state and saves the input
//If the user inputs something, saves to the history
int	ft_minishell_prompt(t_data *ms)
{
	int	control;

	control = ft_prompt_to_input(ms);
	if (ms->input && ms->input[0])
		add_history (ms->input);
	if (!control)
	{
		ms->state = PARSESTATE;
		return (0);
	}
	if (control)
	{
		ms->state = EXITSTATE;
		ms->exit_code = 0;
	}
	return (0);
}