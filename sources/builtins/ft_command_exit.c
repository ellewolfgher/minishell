/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:11:31 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/11 03:43:16 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_long_or_digit(char *str)
{
	long long	num;
	int			chr;

	if (ft_strlen(str) > 20)
		return (0);
	if (ft_strncmp(str, "-9223372036854775808", 21) == 0)
		return (1);
	num = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		chr = *str - '0';
		if (num > (LLONG_MAX - chr) / 10)
			return (0);
		num = num * 10 + chr;
		str++;
	}
	return (1);
}

void	ft_command_exit(t_data *ms)
{
	int			argc;

	argc = ft_token_lst_size(ms->tokens);
	if (argc > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		ms->exit_code = 1;
		ms->state = CLEANSTATE;
	}
	else if (argc == 2 && !ft_long_or_digit(ms->tokens->next->value))
	{
		ft_putstr_fd("exit: numeric argument required\n", 2);
		ms->exit_code = 2;
		ms->state = EXITSTATE;
	}
	else if (argc == 2)
	{
		ms->exit_code = ft_atoll(ms->tokens->next->value);
		ms->state = EXITSTATE;
	}
	else
		ms->state = EXITSTATE;
}
