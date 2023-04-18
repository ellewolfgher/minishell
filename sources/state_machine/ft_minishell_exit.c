/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:27:00 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/17 17:15:34 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Exit function for the minishell.

Function responsibilities:

Retrieve the exit code from the minishell data structure.
If the need_to_exit flag is set to a positive value, print "exit" to the
standard output.
Clear the history of the readline library.
Free dynamically allocated memory for the prompt, input, split, tokens, and
environment variables list.
Exit the minishell with the retrieved exit code.
*/
int	ft_minishell_exit(t_data *ms)
{
	int	code;

	code = ms->exit_code;
	if (ms->need_to_exit > 0)
		write (1, "exit\n", 6);
	rl_clear_history();
	ft_free((void **)&(ms->prompt));
	ft_free((void **)&(ms->input));
	ft_free_matrix((void ***)&(ms->split));
	ft_free_tokens(&(ms->tokens));
	ft_free_varlist(&(ms->env_vars));
	ft_free((void **)&(ms));
	exit(code);
}
