/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:30:45 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/20 11:11:10 by ewolfghe         ###   ########.fr       */
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
			if (tokens->next)
				printf(" ");
		}
		tokens = tokens->next;
	}
	if (!newline)
		printf("\n");
}

/* void	ft_command_echo(t_data *ms, t_execute *cmd)
{
	int			newline;
	int			i;
	char		**args;

	(void)ms;
	args = cmd->args;
	newline = 1;
	i = 1;
	if (args[i] && ft_strcmp(args[i], "-n") == 0)
	{
		newline = 0;
		i++;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
} */
