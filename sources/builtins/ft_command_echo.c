/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:30:45 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/04 19:05:18 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_command_echo(t_data *ms)
{
	int			newline;
	t_tokens	*tokens;

	newline = 0;
	tokens = ms->tokens->next;
	if (tokens && tokens->type == WORDTOKEN && strcmp(tokens->value, "-n") == 0)
	{
		newline = 1;
		tokens = tokens->next;
	}
	while (tokens)
	{
		if (tokens->type == WORDTOKEN)
		{
			printf("%s", tokens->value);
			if (tokens->next && tokens->next->type == WORDTOKEN)
				printf(" ");
		}
		tokens = tokens->next;
	}
	if (!newline)
		printf("\n");
}

/* {
    int n_flag = 0;

    if (tokens->next && tokens->next->type == TOKEN_ARG 
				&& strcmp(tokens->next->value, "-n") == 0)
    {
        n_flag = 1;
        tokens = tokens->next;
    }

    while (tokens)
    {
        if (tokens->type == TOKEN_ARG)
        {
            printf("%s", tokens->value);
            if (tokens->next && tokens->next->type == TOKEN_ARG)
                printf(" ");
        }
        tokens = tokens->next;
    }

    if (!n_flag)
        printf("\n");
}
 */