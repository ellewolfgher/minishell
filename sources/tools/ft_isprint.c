/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:19:46 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/03 18:19:58 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Check if the character is printable
int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	else
		return (0);
}
