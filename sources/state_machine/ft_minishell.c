/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:36:56 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/13 10:52:41 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_check_args(int argc)
{
	if (argc > 1)
	{
		write(2, "Run with ./minishell\n", 22);
		exit (1);
	}
}

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
