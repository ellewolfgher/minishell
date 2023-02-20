/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:15:52 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/02/20 18:46:46 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

//this is here just to test the parser
void	ft_print_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		printf("Token %d: %s\n", i, tokens[i]);
		i++;
	}
}
