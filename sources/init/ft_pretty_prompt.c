/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pretty_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:14:47 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/16 17:16:42 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Sets prompt appearence (because yes)
//Returns 0 if successful and -1 if not
int	ft_pretty_prompt(t_data *ms)
{
	ms->prompt = ft_strdup("\033[1;32m$ \033[0m");
	if (!(ms->prompt))
		return (-1);
	return (0);
}
