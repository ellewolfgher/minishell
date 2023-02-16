/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:39:08 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/02/16 19:28:46 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_data
{
	char				*input;
	struct sigaction	sa_ctrlc;
	struct sigaction	sa_backslash;
}	t_data;

typedef struct s_interactions
{
	int	flag;
}	t_interactions;

t_interactions	*g_interactions;

void	ft_handle_interactive_signal(int signal_num);
t_data	*ft_minishell_init(void);
void	ft_initiate_interactive_signals(t_data *data);

#endif