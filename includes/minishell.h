/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:39:08 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/24 20:12:03 by ridalgo-         ###   ########.fr       */
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
	int					inputnull;
	char				*prompt;
	char				*input;
	char				*spaced;
	char				**split;
	struct s_tokens		*tokens;
	struct s_env_vars	*env_vars;
}	t_data;

typedef struct s_interactions
{
	int	flag;
}	t_interactions;

extern t_interactions	*g_interactions;

int			ft_envvars_init(t_data *ms, char **envp);
void		ft_global_init(void);
int			ft_minishell_init(t_data *ms, char **envp);
int			ft_signals_init(void);

int			ft_minishell_prompt(t_data *ms);
int			ft_prompt_to_input(t_data *ms);

int			ft_parser_onlyspc(char *str);
int			ft_parser_quotes(t_data *ms);
void		ft_parser_split(t_data *ms);
t_tokens	*ft_parser_tokenize(t_data *ms);
char		*ft_parser_spacer(char *buffer, t_data *ms);
int			ft_minishell_parser(t_data *ms);

void		ft_executioner(char **tokens);
void		ft_command_cd(char **tokens);
void		ft_command_pwd(void);
void		ft_command_export(void);
void		ft_command_unset(char **tokens);
void		ft_command_env(char **tokens);
void		ft_command_echo(char **tokens);

void		*ft_free(void *content);
int			ft_minishell_exit(t_data *ms);
void		ft_ongoing_process(void);
void		ft_print_tokens(char **tokens);

void		*ft_calloc(size_t num_elements, size_t element_size);
int			ft_is_whitespace(char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *tobecopied);
int			ft_strlen(const char *str);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif