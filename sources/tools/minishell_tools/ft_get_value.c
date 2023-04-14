/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:05:13 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/14 18:05:38 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
Finds the value of a given variable name in the environment variables list. Takes
the variable name and a pointer to the environment variables list as parameters.
Returns the value of the variable, or NULL if the variable is not found.

Example: if name is "PATH" and env contains the variable "PATH=/usr/bin:/bin",
the function returns "/usr/bin:/bin".
*/
char	*ft_get_value(char *name, t_env_vars *env)
{
	size_t	len;
	char	*str;
	char	*var_value;

	var_value = NULL;
	len = 0;
	while (env)
	{
		str = env->content;
		if (ft_match_variables(str, name))
		{
			while (*str != '=')
				str++;
			str++;
			while (str[len])
				len++;
			var_value = ft_substr(str, 0, len);
		}
		env = env->next;
	}
	return (var_value);
}
