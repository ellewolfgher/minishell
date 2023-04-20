/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:14:16 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/20 14:24:46 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Check which type of token it has to be according to the value
int	ft_token_all(t_data *ms, t_tokens *temp)
{
	int	token_type;

	token_type = ERRTOKEN;
	if (ft_token_operator(temp->value))
		return (OPTOKEN);
	if (ft_token_redirect(temp->value))
		return (REDTOKEN);
	if (ft_token_fd(ms, temp))
		return (FDTOKEN);
	if (ft_token_command(temp))
		token_type = COMTOKEN;
	if (ft_token_word(temp) && token_type != COMTOKEN)
		token_type = WORDTOKEN;
	if (ft_token_builtin(temp->value) && token_type == COMTOKEN)
		token_type = BITOKEN;
	return (token_type);
}

/* int	ft_token_all(t_tokens *temp)
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
} */
