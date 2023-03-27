/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:36:56 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/27 17:01:19 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//ft_minishell_init instantiates all data needed(we can alter the struct later)
//the while loop indicates the prompt
// int	main(void)
// {
// 	t_data	*data;

// 	data = ft_minishell_init();
// 	while (data->input)
// 	{
// 		//printf("You entered: %s\n", data->input);
// 		data->tokens = ft_parser(data->input);
// 		//ft_print_tokens(data->tokens);
// 		ft_executioner(data->tokens);
// 		free(data->input);
// 		//printf("\n");
// 		data->input = readline("\033[1;32m$ \033[0m");
// 		g_interactions->flag = 0;
// 	}
// 	free(data);
// 	free(g_interactions);
// 	return (0);
// }
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
		if (ms->state <= ERRSTATE)
			ft_minishell_exit(ms);
		if (ms->state == INITSTATE)
			ft_minishell_init(ms, envp);
		if (ms->state == PROMPTSTATE)
			ft_minishell_prompt(ms);
		if (ms->state == PARSESTATE)
			ft_minishell_parser(ms);
		if (ms->state == EXECSTATE)
			ft_minishell_executioner(ms);
		if (ms->state == CLEANSTATE)
			ft_minishell_cleaner(ms);
	}
	return (0);
}
