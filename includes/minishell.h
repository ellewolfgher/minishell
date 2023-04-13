/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:39:08 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/13 19:36:42 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//MACHINE STATES
// EXIT: the program is exiting;
# define EXITSTATE		-1
// INIT: initializing some parameters and variables;
# define INITSTATE		0
// PROMPT: the prompt is being displayed and the program is waiting for input;
# define PROMPTSTATE	1
// PARSE: the input is being parsed;
# define PARSESTATE		2
// EXEC: functions and builtins are being called and executed;
# define EXECSTATE		3
// CLEAN: the program is cleaning up memory;
# define CLEANSTATE		4

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

// REDIRECTION TYPES
# define NO_REDIRECT	-1
# define NOPE			0
// HEREDOC: <<
# define HEREDOC		1
// INFILE: <
# define INFILE			2
// OVERWRITE: >
# define OVERWRITE		3
// APPEND: >>
# define APPEND			4

// MAX SIZE FOR PATH
# define PATH_MAX		4096

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <errno.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
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
	int					need_to_exit;
	long long			exit_code;
	int					tok_index;
	int					inputnull;
	char				*prompt;
	char				*input;
	char				**split;
	struct s_tokens		*tokens;
	struct s_env_vars	*env_vars;
	int					pipe_in[2];
	int					pipe_out[2];
}	t_data;

typedef struct s_redirect
{
	int					type;
	char				*target;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_execute
{
	int					block_exec;
	char				*command;
	int					is_builtin;
	char				**args;
	char				**envp;
	struct s_redirect	*red_in;
	struct s_redirect	*red_out;
	int					receives_from_pipe;
	int					sends_to_pipe;
	char				*error_to_print;
}	t_execute;

void		ft_command_cd(t_data *ms);
void		ft_command_echo(t_data *ms);
void		ft_command_env(t_env_vars *env_vars);
void		ft_command_exit(t_data *ms);
void		ft_command_export(t_data *ms);
void		ft_command_pwd(void);
void		ft_command_unset(t_tokens *tokens, t_env_vars **envp);

int			ft_minishell_cleaner(t_data *ms);

char		**ft_searchset_arguments(t_data *ms);
char		*ft_searchset_command(t_data *ms, t_execute *this);
char		**ft_searchset_envvars(t_env_vars *head);
t_redirect	*ft_searchset_input(t_data *ms);
t_redirect	*ft_searchset_output(t_data *ms);
int			ft_searchset_pipe_in(t_data *ms);
int			ft_searchset_pipe_out(t_data *ms);

int			ft_execute_builtin(t_execute *command, t_data *ms, int og_fds[2]);
int			ft_execute_loop(t_execute *command, t_data *ms, int ogfds[2]);
void		ft_execute_output_create(t_execute *command);
int			ft_execute_redirects(t_execute *command, int og_fds[2], t_data *ms);
t_execute	*ft_execute_set_commands(t_data *ms);
int			ft_minishell_execute(t_data *ms);

int			ft_minishell_exit(t_data *ms);

int			ft_envvars_init(t_data *ms, char **envp);
int			ft_minishell_init(t_data *ms, char **envp);
int			ft_signals_init(void);

void		ft_expand_exit_code(t_data *ms);
void		ft_expand_variables(t_data *ms);

int			ft_token_all(t_tokens *temp);
int			ft_token_builtin(char *value);
int			ft_token_command(t_tokens *temp);
int			ft_token_error(t_tokens *temp);
int			ft_token_fd(t_tokens *temp);
int			ft_token_operator(char *value);
int			ft_token_redirect(char *value);
int			ft_token_word(t_tokens *temp);

int			ft_minishell_parser(t_data *ms);

void		ft_parser_categorize(t_tokens *tokens);
void		ft_parser_expand(t_data *ms);
int			ft_parser_onlyspc(char *str);
int			ft_parser_quotes(t_data *ms);
void		ft_parser_rmquotes(t_tokens *tokens);
void		ft_parser_spacer(t_data *ms);
void		ft_parser_split(t_data *ms);
void		ft_parser_tokenize(t_data *ms);

int			ft_minishell_prompt(t_data *ms);

void		ft_envvar_add(t_env_vars **env_vars, char *env_var);
void		ft_envvar_back(t_env_vars **stack, t_env_vars *new);
void		ft_envvar_del(t_env_vars **stack, char *var_name);
char		*ft_envvar_get(t_env_vars *env_vars, const char *name);
int			ft_envvar_lstsize(t_env_vars *env_vars);
t_env_vars	*ft_envvar_new(char *content);
void		ft_envvar_update(char *name, char *value, t_env_vars **env_vars);

void		ft_free_execute(t_execute *command);
void		ft_free_matrix(void ***matrix);
void		ft_free_redirects(t_redirect *this);
void		ft_free_tokens(t_tokens **tokens);
void		ft_free_var(t_env_vars **node);
void		ft_free_varlist(t_env_vars **head);
void		ft_free(void **pointer);

int			ft_atoi(const char *nptr);
long long	ft_atoll(const char *str);
void		*ft_calloc(size_t num_elements, size_t element_size);
int			ft_isalnum(int c);
int			ft_isdigit(char c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *tobecopied);
char		*ft_strjoin_free(char *s1, char *s2);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

int			ft_count_words(char *string);
int			ft_fds_restore(int original_fds[2]);
char		*ft_find_variable(char	*str);
int			ft_is_variable(char c);
int			ft_is_whitespace(char c);
int			ft_isdir(const char *path);
int			ft_match_variables(char *env_var, char *var_name);
t_redirect	*ft_redirect_list(int nodes);
void		ft_signals_default(void);
void		ft_signals_ignore(void);
char		*ft_test_access(char **paths);
int			ft_token_lst_size(t_tokens *lst);
t_tokens	*ft_tokens_iterate(t_data *ms);
void		ft_update_path(t_data *ms, char *oldpwd);

void		ft_print_split(char **tokens);
void		ft_print_tokens(t_tokens *tokens);
void		ft_print_env_vars(t_env_vars *head);
void		ft_print_split(char **tokens);
void		ft_print_tokens(t_tokens *tokens);

#endif