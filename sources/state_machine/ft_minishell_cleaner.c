/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_cleaner.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:56:47 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/20 14:21:45 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Clean up function for the minishell.

Function responsibilities:

Free dynamically allocated memory for the input, split, and tokens.
Reset token index.
Determine the state of the minishell based on the value of need_to_exit.
If need_to_exit is true, set the state to EXITSTATE.
Otherwise, set the state to PROMPTSTATE.
*/
int	ft_minishell_cleaner(t_data *ms)
{
	ft_free((void **)&(ms->input));
	ft_free_matrix((void ***)&(ms->split));
	ft_free_tokens(&(ms->tokens));
	ms->tok_index = 0;
	ms->fd_error = 0;
	if (ms->need_to_exit)
	{
		ms->state = EXITSTATE;
		return (0);
	}
	else
	{
		ms->state = PROMPTSTATE;
		return (0);
	}
}
