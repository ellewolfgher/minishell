/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:36:56 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/17 17:15:52 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Checks the number of command-line arguments and exits if greater than 1.

Function responsibilities:

Exits with an error message if argc > 1, informing the user to run with
./minishell.
*/
static void	ft_check_args(int argc)
{
	if (argc > 1)
	{
		write(2, "Run with ./minishell\n", 22);
		exit (1);
	}
}

/*
Main function of the minishell program.

Function responsibilities:

Checks the number of command-line arguments.
Initializes a t_data structure.
Iterates through the state machine until the EXITSTATE is reached.
*/
int	main(int argc, char *argv[], char **envp)
{
	t_data	*ms;

	(void)argv;
	ft_check_args(argc);
	ms = ft_calloc (1, sizeof(t_data));
	ms->state = INITSTATE;
	while (1)
	{
		if (ms->state == INITSTATE)
			ft_minishell_init(ms, envp);
		if (ms->state == PROMPTSTATE)
			ft_minishell_prompt(ms);
		if (ms->state == PARSESTATE)
			ft_minishell_parser(ms);
		if (ms->state == EXECSTATE)
			ft_minishell_execute(ms);
		if (ms->state == CLEANSTATE)
			ft_minishell_cleaner(ms);
		if (ms->state <= EXITSTATE)
			ft_minishell_exit(ms);
	}
	return (0);
}
