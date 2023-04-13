/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:27:00 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/11 01:33:17 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Stablishes the exit state and frees all memory used by the shell
int	ft_minishell_exit(t_data *ms)
{
	int	code;

	code = ms->exit_code;
	rl_clear_history();
	ft_free((void **)&(ms->prompt));
	ft_free((void **)&(ms->input));
	ft_free_matrix((void ***)&(ms->split));
	ft_free_tokens(&(ms->tokens));
	ft_free_varlist(&(ms->env_vars));
	ft_free((void **)&(ms));
	exit(code);
}
