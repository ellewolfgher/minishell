/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchset_pipe_in.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:30:00 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/12 17:53:45 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
Checks if the current command receives input from a pipe.
Returns 1 if the command receives input from a pipe, otherwise 0.

Example:
If the token list represents the command "echo 'Hello' | cat", the function
returns 1 for the 'cat' command.
*/
int	ft_searchset_pipe_in(t_data *ms)
{
	t_tokens	*aux;

	aux = ft_tokens_iterate(ms);
	if (aux && aux->type == OPTOKEN)
		return (1);
	return (0);
}
