/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:33:56 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/02 00:27:02 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Expands all the variables and the exit code placeholder in the token list.
void	ft_parser_expand(t_data *ms)
{
	ft_expand_exit_code(ms);
	ft_expand_variables(ms);
	return ;
}
