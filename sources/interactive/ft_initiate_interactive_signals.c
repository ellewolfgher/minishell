/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate_interactive_signals.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:19:43 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/02/16 19:25:59 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_initiate_interactive_signals(t_data *data)
{
	data->sa_ctrlc.sa_handler = ft_handle_interactive_signal;
	sigemptyset(&data->sa_ctrlc.sa_mask);
	data->sa_ctrlc.sa_flags = SA_RESTART;
	sigaction(SIGINT, &data->sa_ctrlc, NULL);
	data->sa_backslash.sa_handler = ft_handle_interactive_signal;
	sigemptyset(&data->sa_backslash.sa_mask);
	data->sa_backslash.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &data->sa_backslash, NULL);
	data->input = readline("\033[1;32m$ \033[0m");
	return ;
}
