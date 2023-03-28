/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:28:03 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/28 18:24:07 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_command_cd(t_data *ms)
{
	char	*home_dir;	

	if (ms->tokens->next->value != NULL)
	{
		if (chdir(ms->tokens->next->value) == -1)
			printf("cd: %s: %s\n", ms->tokens->next->value, strerror(errno));
	}
	else
	{
		home_dir = getenv("HOME");
		if (home_dir != NULL)
			chdir(home_dir);
	}
}
