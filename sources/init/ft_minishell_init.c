/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:22:42 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/16 17:44:03 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Changes to be made to ft_initiate_interactive_signals, stopped here
int	ft_minishell_init(t_data	*ms, char **envp)
{
	int	control;

	control = ft_pretty_prompt(ms);
	control = ft_init_env_vars(ms, envp);
	control = ft_initiate_interactive_signals(ms);
	ms->state = PROMPTSTATE;
	if (control)
		ms->state = ERRSTATE;
	return (control);
}
