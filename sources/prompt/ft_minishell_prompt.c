/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_prompt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:53:28 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/17 17:36:40 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Stablishes the prompt state and saves the input

int	ft_minishell_prompt(t_data *ms)
{
	int	control;

	control = ft_prompt_to_input(ms);
	if (!control)
	{
		ms->state = PARSESTATE;
		return (0);
	}
	if (control)
	{
		ms->state = ERRSTATE;
		ms->exit_code = 0;
	}
	return (0);
}
