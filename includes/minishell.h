/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:39:08 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/04 15:43:25 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_TOKENS 100
# define MAX_TOKEN_LEN 100

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_parsing
{
	int		in_quotes;
	char	**tokens;
	char	*current_token;
}	t_parsing;

typedef struct s_parsing_index
{
	int			index;
	char		charac;
	int			t_index;
	int			current_token_index;
}	t_parsing_index;

typedef struct s_data
{
	char				*input;
	char				**tokens;
	struct sigaction	sa_ctrlc;
	struct sigaction	sa_backslash;
}	t_data;

typedef struct s_interactions
{
	int	flag;
}	t_interactions;

extern t_interactions	*g_interactions;

void	ft_global_init(void);
t_data	*ft_minishell_init(void);

void	ft_handle_interactive_signals(int signal_num);
void	ft_initiate_interactive_signals(t_data *data);

char	**ft_parser(char *input);

void	ft_executioner(char **tokens);
void	ft_command_cd(char **tokens);
void	ft_command_pwd(void);
void	ft_command_export(void);
void	ft_command_unset(char **tokens);
void	ft_command_env(char **tokens);
void	ft_command_echo(char **tokens);


void	ft_print_tokens(char **tokens);
void	ft_ongoing_process(void);

void	*ft_calloc(size_t num_elements, size_t element_size);

#endif