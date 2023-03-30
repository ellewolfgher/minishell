/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_spacer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:04:42 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 13:04:09 by ridalgo-         ###   ########.fr       */
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
static void	ft_need_space(int index, t_data *ms)
{
	char	*temporary;

	if (ft_check_before(ms->input, index, ms->input[index]))
	{
		temporary = ft_create_space(ms->input, index);
		ft_free((void **)&(ms->input));
		ms->input = temporary;
		temporary = NULL;
		ft_parser_spacer(ms);
	}
	else if (ft_check_after(ms->input, index, ms->input[index]))
	{
		temporary = ft_create_space(ms->input, index + 1);
		ft_free((void **)&(ms->input));
		ms->input = temporary;
		temporary = NULL;
		ft_parser_spacer(ms);
	}
}

//Creates a space between operators > < | if needed
void	ft_parser_spacer(t_data *ms)
{
	int	index;
	int	singular;
	int	twins;

	index = 0;
	singular = 0;
	twins = 0;
	while (ms->input[index])
	{
		if (ms->input[index] == '\'')
			singular++;
		if (ms->input[index] == '\"')
			twins++;
		if ((twins % 2) || (singular % 2))
		{
			index++;
			continue ;
		}
		if (ms->input[index] == '<' || ms->input[index] == '>'
			|| ms->input[index] == '|')
			ft_need_space(index, ms);
		index++;
	}
}
