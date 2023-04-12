/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_access.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:26:23 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/12 18:26:51 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
Tests each path from the PATH variable to see if the command is accessible
Returns the path to the command or NULL if it doesn't exist

Example:
If paths is ["/usr/bin/program", "/usr/local/bin/program"], and the
program is accessible at "/usr/local/bin/program", the function returns
"/usr/local/bin/program".
*/
char	*ft_test_access(char **paths)
{
	int	index;

	index = 0;
	while (paths[index])
	{
		if (!access(paths[index], F_OK))
		{
			if (!access(paths[index], X_OK))
				return (ft_strdup(paths[index]));
		}
		index++;
	}
	return (NULL);
}
