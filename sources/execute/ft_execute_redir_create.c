/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_redir_create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:54:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/12 17:57:51 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Creates output redirection files if they do not exist.

Example:
If the command has an output redirection "command > output.txt", and the file
"output.txt" does not exist, the function creates the file.
*/
void	ft_execute_redir_create(t_execute *command)
{
	t_redirect	*aux;

	aux = command->red_out;
	while (aux)
	{
		open(aux->target, O_CREAT | O_RDONLY, 0777);
		aux = aux->next;
	}
}
