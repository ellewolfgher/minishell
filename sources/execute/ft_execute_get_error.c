/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_get_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:59:37 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/21 04:02:27 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

/*
Checks if the given path is a valid and executable program. If not, sets an
appropriate error code in the t_data structure and prints an error message.
Returns the exit code as an integer.

If path is set to "/usr/local/bin/directory", and it is a directory,
the exit_code will be 126, and "Is a directory!" will be printed.
If path is set to "/usr/local/bin/nonexistent", and it is not executable,
the exit_code will be 127, and "command not found!" will be printed.
*/

static int	ft_check_path(char *path, t_data *ms)
{
	struct stat	sb;

	ft_memset(&sb, 0, sizeof(struct stat));
	if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		ms->exit_code = 126;
		return (ms->exit_code);
	}
	if (access(path, X_OK))
	{
		ms->exit_code = 127;
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		return (ms->exit_code);
	}
	return (0);
}

int	ft_execute_get_error(char *path, t_data *ms)
{
	int		exit_code;
	char	*path_copy;

	if (!path || !*path)
	{
		ms->exit_code = 1;
		return (ms->exit_code);
	}
	exit_code = 0;
	path_copy = ft_strdup(path);
	if (!path_copy)
	{
		ms->exit_code = 1;
		return (ms->exit_code);
	}
	ms->exit_code = ft_check_path(path_copy, ms);
	ft_free((void **)&path_copy);
	return (ms->exit_code);
}
