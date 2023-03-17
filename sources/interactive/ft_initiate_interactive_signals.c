/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate_interactive_signals.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:19:43 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/16 16:49:53 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_initiate_interactive_signals(t_data *ms)
{
	ms->sa_ctrlc.sa_handler = ft_handle_interactive_signals;
	sigemptyset(&ms->sa_ctrlc.sa_mask);
	ms->sa_ctrlc.sa_flags = SA_RESTART;
	sigaction(SIGINT, &ms->sa_ctrlc, NULL);
	ms->sa_backslash.sa_handler = ft_handle_interactive_signals;
	sigemptyset(&ms->sa_backslash.sa_mask);
	ms->sa_backslash.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &ms->sa_backslash, NULL);
	ms->input = readline("\033[1;32m$ \033[0m");
	return (0);
}
