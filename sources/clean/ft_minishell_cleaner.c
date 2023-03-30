/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_cleaner.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:56:47 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 11:29:55 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_minishell_cleaner(t_data *ms)
{
	if (ms->input != ms->spaced && ms->spaced)
		ft_free(ms->spaced);
	ft_free(ms->input);
	ft_free_matrix(ms->split);
	ft_free_tokens(ms->tokens);
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
