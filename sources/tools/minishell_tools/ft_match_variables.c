/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_variables.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:35:24 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 09:03:54 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Checks if a given environment variable env_var
//matches the given variable name var_name.
int	ft_match_variables(char *env_var, char *var_name)
{
	size_t		var_size;

	var_size = ft_strlen(var_name);
	if (!ft_strncmp(env_var, var_name, var_size)
		&& *(env_var + var_size) == '=')
		return (1);
	return (0);
}
