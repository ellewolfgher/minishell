/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_prompt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:53:28 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/19 21:25:46 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Reads the user input and trims leading/trailing spaces.

Function responsibilities:

Reads user input using readline().
Trims leading and trailing spaces from the input string.
Returns 0 if input is successfully read, 1 otherwise.
*/
static int	ft_prompt_to_input(t_data *ms)
{
	char	*aux;

	ms->input = readline(ms->prompt);
	if (ms->input)
	{
		if (ms->input[0] == '\0')
		{
			ft_free((void **)&(ms->input));
			return (JUST_ENTER);
		}
		aux = ms->input;
		ms->input = ft_strtrim(aux, " ");
		if (!ms->input)
		{
			ft_free((void **)&(ms->input));
			return (JUST_ENTER);
		}
		ft_free((void **)&(aux));
		return (0);
	}
	else if (!(ms->input))
		return (CTRL_D);
	return (0);
}

/*
Handles the minishell prompt and input history.

Function responsibilities:

Calls ft_prompt_to_input() to read user input.
Adds the input to the command history if it is non-empty.
Sets the state to PARSESTATE if input is read, otherwise to EXITSTATE.
*/
int	ft_minishell_prompt(t_data *ms)
{
	int	control;

	control = ft_prompt_to_input(ms);
	if (ms->input && ms->input[0])
		add_history (ms->input);
	if (!control)
		ms->state = PARSESTATE;
	if (control == CTRL_D)
	{
		ms->state = EXITSTATE;
		ms->need_to_exit = 1;
		ms->exit_code = 0;
	}
	if (control == JUST_ENTER)
		ms->state = PROMPTSTATE;
	return (0);
}
