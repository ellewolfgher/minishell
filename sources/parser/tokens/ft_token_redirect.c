/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:38:52 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/03 18:39:17 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Checks if the token is a redirect
int	ft_token_redirect(char *value)
{
	if (!ft_strcmp(value, ">"))
		return (1);
	if (!ft_strcmp(value, ">>"))
		return (1);
	if (!ft_strcmp(value, "<"))
		return (1);
	if (!ft_strcmp(value, "<<"))
		return (1);
	return (0);
}
