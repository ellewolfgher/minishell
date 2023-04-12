/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fds_restore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:42:52 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/12 18:21:22 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
Restores the standard input and output file descriptors.
Takes an array of original file descriptors as a parameter.
Returns 1 after restoring the file descriptors.

Example:
If the og_fds[0] and og_fds[1] are not equal to NO_REDIRECT, the
function restores the standard input and output file descriptors.
*/
int	ft_fds_restore(int og_fds[2])
{
	if (og_fds[0] != NO_REDIRECT)
		dup2(og_fds[0], STDIN_FILENO);
	if (og_fds[1] != NO_REDIRECT)
		dup2(og_fds[1], STDOUT_FILENO);
	return (1);
}
