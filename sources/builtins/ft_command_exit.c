/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:11:31 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/15 21:03:39 by ewolfghe         ###   ########.fr       */
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

void	ft_command_exit(t_data *ms, t_execute *cmd)
{
	int			argc;

	argc = ft_args_len(cmd->args);
	if (argc > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		ms->exit_code = 1;
	}
	else if (argc == 2 && !ft_long_or_digit(cmd->args[1]))
	{
		ft_putstr_fd("exit: numeric argument required\n", 2);
		ms->exit_code = 2;
		ms->need_to_exit = 1;
	}
	else if (argc == 2)
	{
		ms->exit_code = (unsigned char)ft_atoi(cmd->args[1]);
		ms->need_to_exit = 1;
	}
	else
		ms->need_to_exit = 1;
}
