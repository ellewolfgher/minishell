/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:36:56 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/02/20 18:18:07 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//ft_minishell_init instantiates all data needed(we can alter the struct later)
//the while loop indicates the prompt
int	main(void)
{
	t_data	*data;

	data = ft_minishell_init();
	while (data->input)
	{
		printf("You entered: %s\n", data->input);
		data->tokens = ft_parser(data->input);
		ft_print_tokens(data->tokens);
		free(data->input);
		printf("\n");
		data->input = readline("\033[1;32m$ \033[0m");
		g_interactions->flag = 0;
	}
	free(data);
	free(g_interactions);
	return (0);
}
