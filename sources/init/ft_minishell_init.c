/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:22:42 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 15:56:07 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Sets prompt appearence (because yes)
//Returns 0 if successful and -1 if not
static int	ft_pretty_prompt(t_data *ms)
{
	ms->prompt = ft_strdup("\xf0\x9f\x90\x9a");
	if (!(ms->prompt))
		return (-1);
	return (0);
}

//Changes to be made to ft_initiate_interactive_signals, stopped here
int	ft_minishell_init(t_data *ms, char **envp)
{
	int	control;

	ms->state = PROMPTSTATE;
	control = ft_pretty_prompt(ms);
	if (control)
		ms->state = EXITSTATE;
	control = ft_signals_init();
	if (control)
		ms->state = EXITSTATE;
	control = ft_envvars_init(ms, envp);
	if (control)
		ms->state = EXITSTATE;
	return (control);
}
