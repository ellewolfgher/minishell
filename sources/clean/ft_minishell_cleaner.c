/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_cleaner.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:56:47 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/27 17:38:54 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_minishell_cleaner(t_data *ms)
{
	if (ms->input != ms->spaced && ms->spaced)
		ms->spaced = ft_free(ms->spaced);
	ms->input = ft_free(ms->input);
	ms->split = ft_free_double(ms);
	ms->tokens = ft_free_tokens(ms);
	if (ms->tracking < 0)
	{
		ms->tracking = 0;
		ms->state = ERRSTATE;
		return (0);
	}
	if (ms->tracking > 0)
	{
		ms->state = ERRSTATE;
		return (0);
	}
	else
	{
		ms->state = PROMPTSTATE;
		return (0);
	}
}
