/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:22:25 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 09:02:35 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Checks if a character is alphanumeric, which can be a digit or a letter.
int	ft_isalnum(int c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91)
		|| (c > 96 && c < 123))
		return (8);
	return (0);
}
