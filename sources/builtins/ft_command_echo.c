/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:30:45 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/07 18:47:00 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Print the tokens
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
