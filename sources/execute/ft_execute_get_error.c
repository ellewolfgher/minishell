/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_get_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:59:37 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/19 10:53:03 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Checks if the given path is a valid and executable program. If not, sets an
appropriate error code in the t_data structure and prints an error message.
Returns the exit code as an integer.

If path is set to "/usr/local/bin/directory", and it is a directory,
the exit_code will be 126, and "Is a directory!" will be printed.
If path is set to "/usr/local/bin/nonexistent", and it is not executable,
the exit_code will be 127, and "command not found!" will be printed.
*/
int	ft_execute_get_error(char *path, t_data *ms)
{
	struct stat	sb;

	if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		ms->exit_code = 126;
		printf("Is a directory\n");
	}
	if (!path)
		ms->exit_code = 1;
	else if (access(path, X_OK))
	{
		ms->exit_code = 127;
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
	}
	return (ms->exit_code);
}
