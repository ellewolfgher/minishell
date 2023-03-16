/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:27:00 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/16 16:30:56 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//this function is called when the program is finished or has to exit
int	ft_clean_exit(t_data *ms)
{
	int	code;

	code = ms->exit_code;
	free(ms);
	exit (code);
}
