/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:28:03 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/07 18:47:30 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Count the number of tokens
static size_t	count_tokens(t_tokens *head)
{
	size_t	count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

//Change the current working directory
void	ft_command_cd(t_data *ms)
{
	char	*home_dir;
	size_t	tokens_count;

	tokens_count = count_tokens(ms->tokens);
	if (tokens_count > 1 && ms->tokens->next->value)
	{
		if (chdir(ms->tokens->next->value) == -1)
			printf("cd: %s: %s\n", ms->tokens->next->value, strerror(errno));
	}
	else if (tokens_count == 1)
	{
		home_dir = getenv("HOME");
		if (home_dir != NULL)
			chdir(home_dir);
	}
}
