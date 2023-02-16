/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:15:49 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/02/16 19:26:56 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_handle_interactive_signal(int signal_num)
{
	if (signal_num == SIGINT)
		g_interactions->flag = 1;
	else if (signal_num == SIGQUIT)
		g_interactions->flag = 0;
}
