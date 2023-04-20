/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:35:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/20 14:31:02 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	ft_print_error(t_data *ms, t_tokens *temp, int acs)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(temp->value, STDERR_FILENO);
	if (acs == 2)
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	else if (acs == 3)
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
	ms->exit_code = 1;
}

//Checks if the previous token is a redirect, if it is, it is a file descriptor
int	ft_token_fd(t_data *ms, t_tokens *temp)
{
	int			acs;
	char		*val;

	acs = 0;
	val = temp->value;
	if (temp->prev && temp->prev->type == REDTOKEN)
	{
		if (access(val, F_OK) != 0 || access(val, R_OK | X_OK | W_OK) != 0)
		{
			if (!ms->fd_error)
			{
				if (access(val, F_OK) != 0)
					acs = 2;
				else if (access(val, R_OK | X_OK | W_OK) != 0)
					acs = 3;
				ft_print_error(ms, temp, acs);
				ms->fd_error = 1;
			}
		}
		return (1);
	}
	return (0);
}
