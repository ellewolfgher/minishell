/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:51:36 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/14 12:11:06 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Creates a new process by duplicating the calling process using fork(). If the
fork fails, prints an error message and exits with status -1.
Returns the process ID (pid) of the child process.

Example:
pid_t child_pid = ft_execute_fork();
If the fork is successful, child_pid will store the process ID of the child.
*/
pid_t	ft_execute_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		write(2, "error: couldn't fork the process\n", 34);
		exit(-1);
	}
	return (pid);
}
