/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_spacer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:04:42 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 11:22:19 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Checks if the character BEFORE operator should be a [space];
//Still not working with a single character on the first arg like a> 'a'
static int	ft_check_before(char *buffer, int index, char operator)
{
	int	flag;

	flag = 0;
	if (index == 0)
		return (0);
	index--;
	while (index)
	{
		if (buffer[index] == operator)
		{
			if (flag)
				return (1);
			flag++;
		}
		if (flag && buffer[index - 1] != operator)
			return (0);
		else if (buffer[index] != ' ')
			return (1);
		else if (buffer[index] == ' ')
			return (0);
		index--;
	}
	return (0);
}

//Checks if the character AFTER operator should be a [space];
static int	ft_check_after(char *buffer, int index, char operator)
{
	int	flag;

	flag = 0;
	index++;
	while (index)
	{
		if (buffer[index] == operator)
		{
			if (flag == 2)
				return (1);
			flag++;
		}
		if (flag && buffer[index + 1] != operator)
			return (0);
		else if (buffer[index] != ' ' && buffer[index] != 0)
			return (1);
		else if (buffer[index] == ' ' || buffer[index] == 0)
			return (0);
		index++;
	}
	return (0);
}

//Creates a space before or after the operator
static char	*ft_create_space(char *buffer, int num)
{
	char	*ret;
	int		index;
	int		jndex;

	index = 0;
	jndex = 0;
	ret = (char *)malloc (sizeof (char) * (ft_strlen(buffer) + 2));
	while (buffer[index])
	{
		if (index == num)
		{
			ret[jndex] = ' ';
			jndex++;
		}
		ret[jndex] = buffer[index];
		index++;
		jndex++;
	}
	ret[jndex] = 0;
	return (ret);
}

//Checks if there is a need for a space before or after the operator
static char	*ft_need_space(char *str, int index, t_data *ms)
{
	char	*temporary;

	if (ft_check_before(str, index, str[index]))
	{
		temporary = ft_create_space(str, index);
		ft_free(str);
		str = temporary;
		temporary = NULL;
		return (ft_parser_spacer(str, ms));
	}
	if (ft_check_after(str, index, str[index]))
	{
		temporary = ft_create_space(str, index + 1);
		ft_free(str);
		str = temporary;
		temporary = NULL;
		return (ft_parser_spacer(str, ms));
	}
	ms->inputnull = 1;
	return (str);
}

//Creates a space between operators > < | if needed
char	*ft_parser_spacer(char *str, t_data *ms)
{
	int		index;
	int		singular;
	int		twins;

	index = 0;
	singular = 0;
	twins = 0;
	while (str[index])
	{
		if (str[index] == '\'')
			singular++;
		if (str[index] == '\"')
			twins++;
		if ((twins % 2) || (singular % 2))
		{
			index++;
			continue ;
		}
		if (str[index] == '<' || str[index] == '>' || str[index] == '|')
			str = ft_need_space(str, index, ms);
		index++;
	}
	ms->inputnull = 1;
	return (str);
}
