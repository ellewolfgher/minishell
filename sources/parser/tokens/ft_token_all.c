/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:14:16 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/20 15:30:27 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Check which type of token it has to be according to the value
int	ft_token_all(t_tokens *temp)
{
	int	token_type;

	token_type = ERRTOKEN;
	if (ft_token_operator(temp->value))
		return (OPTOKEN);
	if (ft_token_redirect(temp->value))
		return (REDTOKEN);
	if (ft_token_fd(temp))
		return (FDTOKEN);
	if (ft_token_word(temp))
		token_type = WORDTOKEN;
	if (ft_token_command(temp) && token_type == WORDTOKEN)
		token_type = COMTOKEN;
	if (ft_token_builtin(temp->value) && token_type == COMTOKEN)
		token_type = BITOKEN;
	return (token_type);
}
