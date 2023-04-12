/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:41:07 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/12 18:08:48 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
Free the memory allocated for the execute struct command, used to store the
information about the command to be executed.
*/
void	ft_free_execute(t_execute *command)
{
	if (!command)
		return ;
	if (command->command)
		ft_free((void **)&command->command);
	if (command->args)
		ft_free_matrix((void ***)&command->args);
	if (command->envp)
		ft_free_matrix((void ***)&command->envp);
	if (command->error_to_print)
		ft_free((void **)&command->error_to_print);
	if (command->red_in)
		ft_free_redirects(command->red_in);
	if (command->red_out)
		ft_free_redirects(command->red_out);
	ft_free((void **)&command);
	return ;
}
