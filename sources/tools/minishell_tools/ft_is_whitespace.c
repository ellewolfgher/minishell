/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:13:22 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 09:02:52 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Checks if a character is a space, a tab or a new line.
int	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}
