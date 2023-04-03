/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:39:08 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/03 18:52:30 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//MACHINE STATES
// ERR: an error has occurred;
# define ERRSTATE		0
// INIT: initializing some parameters and variables;
# define INITSTATE		1
// PROMPT: the prompt is being displayed and the program is waiting for input;
# define PROMPTSTATE	2
// PARSE: the input is being parsed;
# define PARSESTATE		3
// EXEC: functions and builtins are being called and executed;
# define EXECSTATE		4
// CLEAN: the program is cleaning up memory;
# define CLEANSTATE		5

// TOKEN TYPES
// ERR: should return error if used, or is of unknown type;
# define ERRTOKEN		-1
// COM: is a command;
# define COMTOKEN		0
// BI:is a built in command;
# define BITOKEN		1
// WORD: is an argument after the command;
# define WORDTOKEN		2
// OP: is a control operator;
# define OPTOKEN		3
// RED: is a fd redirection operator;
# define REDTOKEN		4
// FD: is a file descriptor;
# define FDTOKEN		5

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

int			ft_envvars_init(t_data *ms, char **envp);
void		ft_global_init(void);
int			ft_minishell_init(t_data *ms, char **envp);
int			ft_signals_init(void);

int			ft_minishell_prompt(t_data *ms);
int			ft_prompt_to_input(t_data *ms);

void		ft_expand_exit_code(t_data *ms);
void		ft_expand_variables(t_data *ms);
void		ft_parser_categorize(t_tokens *tokens);
void		ft_parser_expand(t_data *ms);
int			ft_parser_onlyspc(char *str);
int			ft_parser_quotes(t_data *ms);
void		ft_parser_split(t_data *ms);
void		ft_parser_tokenize(t_data *ms);
void		ft_parser_spacer(t_data *ms);
int			ft_minishell_parser(t_data *ms);

int			ft_token_all(t_tokens *temp);
int			ft_token_builtin(char *value);
int			ft_token_command(t_tokens *temp);
int			ft_token_error(t_tokens *temp);
int			ft_token_fd(t_tokens *temp);
int			ft_token_operator(char *value);
int			ft_token_redirect(char *value);
int			ft_token_word(t_tokens *temp);

void		ft_minishell_executioner(t_data *ms);
void		ft_command_cd(t_data *ms);
void		ft_command_pwd(void);
void		ft_command_export(void);
void		ft_command_unset(char **tokens);
void		ft_command_env(char **tokens);
void		ft_command_echo(char **tokens);

int			ft_minishell_cleaner(t_data *ms);

void		ft_free(void **pointer);
void		ft_free_matrix(void ***matrix);
void		ft_free_tokens(t_tokens **tokens);
int			ft_minishell_exit(t_data *ms);
void		ft_print_split(char **tokens);
void		ft_print_tokens(t_tokens *tokens);
void		ft_print_env_vars(t_env_vars *head);
void		ft_free_split(char **array);
int			ft_minishell_exit(t_data *ms);
void		ft_print_split(char **tokens);
void		ft_print_tokens(t_tokens *tokens);

char		*ft_find_variable(char	*str);
int			ft_match_variables(char *env_var, char *var_name);
int			ft_is_whitespace(char c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_is_variable(char c);
char		*ft_itoa(int n);
int			ft_count_words(char *string);
int			ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_calloc(size_t num_elements, size_t element_size);
t_env_vars	*ft_new_var(char *content);
void		ft_lstadd_back(t_env_vars **stack, t_env_vars *new);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *tobecopied);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);

t_env_vars	*ft_env_var_new(char *content);
void		ft_env_add_var(t_env_vars **env_vars, char *env_var);
void		ft_env_back_add(t_env_vars **env_vars, t_env_vars *new);

#endif