/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:36:56 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/02/16 19:29:56 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//this is here just to test ctrl+c, ctrl+backslash and ctrl+d
void	ft_ongoing_process(void)
{
	int	i;

	i = 0;
	while (i < 50 && !g_interactions->flag)
	{
		printf("g_interactions->flag: %d\n", g_interactions->flag);
		usleep(100000);
		i++;
	}
}

//ft_minishell_init instantiates all data needed(we can alter the struct later)
//the while loop indicates the prompt
int	main(void)
{
	t_data	*data;

	data = ft_minishell_init();
	while (data->input)
	{
		printf("You entered: %s\n", data->input);
		ft_ongoing_process();
		free(data->input);
		printf("\n");
		data->input = readline("\033[1;32m$ \033[0m");
		g_interactions->flag = 0;
	}
	free(data);
	free(g_interactions);
	return (0);
}
