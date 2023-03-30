/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:39:08 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 12:58:53 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//state definitions
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

typedef struct s_env_vars
{
	char				*content;
	struct s_env_vars	*next;
}	t_env_vars;

typedef struct s_tokens
{
	char			*value;
	int				type;
	int				index;
	struct s_tokens	*next;
	struct s_tokens	*prev;
}	t_tokens;

typedef struct s_data
{
	int					state;
	int					exit_code;
	int					tracking;
	int					inputnull;
	char				*prompt;
	char				*input;
	char				**split;
	struct s_tokens		*tokens;
	struct s_env_vars	*env_vars;
}	t_data;

int		ft_envvars_init(t_data *ms, char **envp);
int		ft_minishell_init(t_data *ms, char **envp);
int		ft_signals_init(void);

int		ft_minishell_prompt(t_data *ms);
int		ft_prompt_to_input(t_data *ms);

int		ft_parser_onlyspc(char *str);
int		ft_parser_quotes(t_data *ms);
void	ft_parser_split(t_data *ms);
void	ft_parser_tokenize(t_data *ms);
void	ft_parser_spacer(t_data *ms);
int		ft_minishell_parser(t_data *ms);

void	ft_minishell_executioner(t_data *ms);
void	ft_command_cd(t_data *ms);
void	ft_command_pwd(void);
void	ft_command_export(void);
void	ft_command_unset(char **tokens);
void	ft_command_env(char **tokens);
void	ft_command_echo(char **tokens);

int		ft_minishell_cleaner(t_data *ms);

void	ft_free(void **pointer);
void	ft_free_matrix(void ***matrix);
void	ft_free_tokens(t_tokens **tokens);
int		ft_minishell_exit(t_data *ms);
void	ft_print_split(char **tokens);
void	ft_print_tokens(t_tokens *tokens);

void	*ft_calloc(size_t num_elements, size_t element_size);
int		ft_is_whitespace(char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *tobecopied);
int		ft_strlen(const char *str);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_count_words(char *string);

#endif