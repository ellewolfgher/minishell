/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:39:08 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/16 17:39:52 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAX_TOKENS 100
# define MAX_TOKEN_LEN 100

# define ERRSTATE		0
# define INITSTATE		1
# define PROMPTSTATE	2
# define PARSESTATE		3
# define EXECSTATE		4
# define CLEANSTATE		5

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

typedef struct s_env_vars
{
	char				*content;
	struct s_env_vars	*next;
}	t_env_vars;

typedef struct s_data
{
	int					state;
	int					exit_code;
	char				*prompt;
	char				*input;
	char				**tokens;
	struct s_env_vars	*env_vars;
	struct sigaction	sa_ctrlc;
	struct sigaction	sa_backslash;
}	t_data;

typedef struct s_interactions
{
	int	flag;
}	t_interactions;

extern t_interactions	*g_interactions;

void	ft_global_init(void);
int		ft_minishell_init(t_data	*ms, char **envp);
int		ft_pretty_prompt(t_data *ms);
int		ft_init_env_vars(t_data *ms, char **envp);

void	ft_handle_interactive_signals(int signal_num);
int		ft_initiate_interactive_signals(t_data *ms);

char	**ft_parser(char *input);

void	ft_executioner(char **tokens);
void	ft_command_cd(char **tokens);
void	ft_command_pwd(void);
void	ft_command_export(void);
void	ft_command_unset(char **tokens);
void	ft_command_env(char **tokens);
void	ft_command_echo(char **tokens);

int		ft_clean_exit(t_data *ms);
void	ft_ongoing_process(void);
void	ft_print_tokens(char **tokens);

void	*ft_calloc(size_t num_elements, size_t element_size);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *tobecopied);

#endif