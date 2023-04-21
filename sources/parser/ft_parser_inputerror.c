/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_inputerror.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:43:19 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/20 21:55:53 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void checkwrite(t_data *ms, t_tokens *aux)
{
	if (access(aux->value, W_OK))
	{
		if (!ms->fd_error)
		{
			if (!ft_strcmp(aux->prev->value, "<"))
			{
				ft_putstr_fd("minishell: ", STDERR_FILENO);
				ft_putstr_fd(ms->tokens->value, STDERR_FILENO);
				ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
				ms->exit_code = 1;
				ms->fd_error = 1;
			}
		}
	}
}

static void checkfile(t_data *ms, t_tokens *aux)
{
	if (access(aux->value, F_OK))
	{
		if (!ms->fd_error)
		{
			if (!ft_strcmp(aux->prev->value, "<"))
			{
				ft_putstr_fd("minishell: ", STDERR_FILENO);
				ft_putstr_fd(ms->tokens->value, STDERR_FILENO);
				ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
				ms->exit_code = 1;
				ms->fd_error = 1;
			}
		}
	}
}

void	ft_parser_inputerror(t_data *ms)
{
	t_tokens	*aux;

	aux = ms->tokens;
	while (aux)
	{
		if (aux->type == FDTOKEN)
		{
			checkfile(ms, aux);
			checkwrite(ms, aux);
		}
		aux = aux->next;
	}
}
