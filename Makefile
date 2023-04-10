NAME = minishell

PATH_INCS = ./includes/
PATH_OBJS = ./objects/
PATH_SRCS = ./sources/
PATH_BUIL = $(PATH_SRCS)builtins/
PATH_CLEA = $(PATH_SRCS)clean/

PATH_EXEC = $(PATH_SRCS)execute/
PATH_SAST = $(PATH_EXEC)search_and_set/

PATH_EXIT = $(PATH_SRCS)exit/
PATH_INIT = $(PATH_SRCS)init/

PATH_PARS = $(PATH_SRCS)parser/
PATH_EXPN = $(PATH_PARS)expansion/
PATH_TKNS = $(PATH_PARS)tokens/

PATH_PROM = $(PATH_SRCS)prompt/

PATH_TOOL = $(PATH_SRCS)tools/
PATH_EVTL = $(PATH_TOOL)envvar_tools/
PATH_FRTL = $(PATH_TOOL)free_tools/
PATH_LBTL = $(PATH_TOOL)lib_tools/
PATH_MSTL = $(PATH_TOOL)minishell_tools/

SRCS = $(addprefix $(PATH_SRCS),\
		ft_main.c) \
		$(addprefix $(PATH_BUIL),\
		ft_command_cd.c \
		ft_command_pwd.c \
		ft_command_export.c \
		ft_command_echo.c \
		ft_command_env.c \
		ft_command_unset.c) \
		$(addprefix $(PATH_CLEA),\
		ft_minishell_cleaner.c) \
		$(addprefix $(PATH_EXEC),\
		ft_exec_one_command.c \
		ft_execute_loop.c \
		ft_execute_redir_create.c \
		ft_execute_set_commands.c \
		ft_minishell_execute.c) \
		$(addprefix $(PATH_SAST),\
		ft_searchset_arguments.c \
		ft_searchset_command.c \
		ft_searchset_envvars.c \
		ft_searchset_input.c \
		ft_searchset_output.c \
		ft_searchset_pipe_in.c \
		ft_searchset_pipe_out.c) \
		$(addprefix $(PATH_EXIT),\
		ft_minishell_exit.c) \
		$(addprefix $(PATH_INIT),\
		ft_envvars_init.c \
		ft_minishell_init.c \
		ft_signals_init.c) \
		$(addprefix $(PATH_PARS),\
		ft_parser_categorize.c \
		ft_parser_expand.c \
		ft_parser_quotes.c \
		ft_parser_tokenize.c \
		ft_parser_rmquotes.c \
		ft_parser_spacer.c \
		ft_parser_split.c \
		ft_parser_onlyspc.c \
		ft_minishell_parser.c) \
		$(addprefix $(PATH_EXPN),\
		ft_expand_exit_code.c \
		ft_expand_variables.c) \
		$(addprefix $(PATH_TKNS),\
		ft_token_all.c \
		ft_token_builtin.c \
		ft_token_command.c \
		ft_token_error.c \
		ft_token_fd.c \
		ft_token_operator.c \
		ft_token_redirect.c \
		ft_token_word.c) \
		$(addprefix $(PATH_PROM),\
		ft_minishell_prompt.c \
		ft_prompt_to_input.c) \
		$(addprefix $(PATH_EVTL),\
		ft_envvar_add.c \
		ft_envvar_back.c \
		ft_envvar_del.c \
		ft_envvar_get.c \
		ft_envvar_lstsize.c \
		ft_envvar_new.c) \
		$(addprefix $(PATH_FRTL),\
		ft_free_matrix.c \
		ft_free_tokens.c \
		ft_free_var.c \
		ft_free_varlist.c \
		ft_free.c) \
		$(addprefix $(PATH_LBTL),\
		ft_calloc.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strtrim.c \
		ft_substr.c) \
		$(addprefix $(PATH_MSTL),\
		ft_count_words.c \
		ft_fds_restore.c \
		ft_find_variable.c \
		ft_is_variable.c \
		ft_is_whitespace.c \
		ft_isdir.c \
		ft_match_variables.c \
		ft_redirect_list.c \
		ft_signals_ignore.c \
		ft_test_tools.c \
		ft_token_lst_size.c \
		ft_tokens_iterate.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I $(PATH_INCS) -I /usr/local/Cellar/readline/8.2.1/include/

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) -L/usr/local/Cellar/readline/8.2.1/lib -lreadline

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)builtins/
	@mkdir -p $(PATH_OBJS)clean/
	@mkdir -p $(PATH_OBJS)execute/
	@mkdir -p $(PATH_OBJS)execute/search_and_set/
	@mkdir -p $(PATH_OBJS)exit/
	@mkdir -p $(PATH_OBJS)init/
	@mkdir -p $(PATH_OBJS)parser/
	@mkdir -p $(PATH_OBJS)parser/expansion/
	@mkdir -p $(PATH_OBJS)parser/tokens/
	@mkdir -p $(PATH_OBJS)prompt/
	@mkdir -p $(PATH_OBJS)tools/
	@mkdir -p $(PATH_OBJS)tools/envvar_tools/
	@mkdir -p $(PATH_OBJS)tools/free_tools/
	@mkdir -p $(PATH_OBJS)tools/lib_tools/
	@mkdir -p $(PATH_OBJS)tools/minishell_tools/
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -rf $(PATH_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

r: all
	@clear
	@./minishell
n:
	@clear
	@norminette ./sources ./includes

vg: all
	@clear
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./minishell

PHONY: all clean fclean re n r