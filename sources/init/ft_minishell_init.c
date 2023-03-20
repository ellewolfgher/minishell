/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:22:42 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/20 12:46:01 by ridalgo-         ###   ########.fr       */
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

	control = ft_pretty_prompt(ms);
	control = ft_signals_init();
	control = ft_envvars_init(ms, envp);
	ms->state = PROMPTSTATE;
	if (control)
		ms->state = ERRSTATE;
	return (control);
}
