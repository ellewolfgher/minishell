/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:39:08 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 12:41:23 by ewolfghe         ###   ########.fr       */
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

//tokentype definitions
# define PIPE			1
# define SEMICOLON		2
# define REDIR_IN		3

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
	char				*spaced;
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

int			ft_parser_onlyspc(char *str);
int			ft_parser_quotes(t_data *ms);
void		ft_parser_split(t_data *ms);
void		ft_parser_tokenize(t_data *ms);
char		*ft_parser_spacer(char *buffer, t_data *ms);
int			ft_minishell_parser(t_data *ms);

void		ft_minishell_executioner(t_data *ms);
void		ft_command_cd(t_data *ms);
void		ft_command_pwd(void);
void		ft_command_export(void);
void		ft_command_unset(char **tokens);
void		ft_command_env(char **tokens);
void		ft_command_echo(char **tokens);

int			ft_minishell_cleaner(t_data *ms);

void		ft_free(void *pointer);
void		ft_free_matrix(char **matrix);
void		ft_free_tokens(t_tokens *tokens);
void		ft_free_split(char **array);
int			ft_minishell_exit(t_data *ms);
void		ft_print_split(char **tokens);
void		ft_print_tokens(t_tokens *tokens);

int			ft_is_whitespace(char c);
int			ft_count_words(char *string);
int			ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_calloc(size_t num_elements, size_t element_size);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *tobecopied);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);

t_env_var	*ft_env_var_new(char *content);
void		ft_env_add_var(t_env_vars **env_vars, char *env_var);
void		ft_env_back_add(t_env_var **env_vars, t_env_var *new);

#endif