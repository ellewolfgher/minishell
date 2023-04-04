/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:27:00 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 09:13:15 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Stablishes the exit state and frees the memory
int	ft_minishell_exit(t_data *ms)
{
	int	code;

	code = ms->exit_code;
	ft_free((void **)&(ms->prompt));
	ft_free((void **)&(ms));
	exit (code);
}