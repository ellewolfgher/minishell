NAME = minishell

PATH_INCS = ./includes/
PATH_OBJS = ./objects/
PATH_SRCS = ./sources/
PATH_EXEC = $(PATH_SRCS)exec/
PATH_BUIL = $(PATH_SRCS)builtins/
PATH_PARS = $(PATH_SRCS)parser/
PATH_INIT = $(PATH_SRCS)init/
PATH_PROM = $(PATH_SRCS)prompt/
PATH_TOOL = $(PATH_SRCS)tools/
PATH_CLEA = $(PATH_SRCS)clean/

SRCS = $(addprefix $(PATH_SRCS),\
		ft_main.c) \
		$(addprefix $(PATH_EXEC),\
		ft_minishell_executioner.c) \
		$(addprefix $(PATH_BUIL),\
		ft_cd.c \
		ft_pwd.c \
		ft_export.c \
		ft_echo.c \
		ft_env.c \
		ft_unset.c) \
		$(addprefix $(PATH_PARS),\
		ft_parser_quotes.c \
		ft_parser_tokenize.c \
		ft_parser_spacer.c \
		ft_parser_split.c \
		ft_parser_onlyspc.c \
		ft_minishell_parser.c) \
		$(addprefix $(PATH_CLEA),\
		ft_minishell_cleaner.c) \
		$(addprefix $(PATH_INIT),\
		ft_envvars_init.c \
		ft_minishell_init.c \
		ft_signals_init.c) \
		$(addprefix $(PATH_PROM),\
		ft_minishell_prompt.c \
		ft_prompt_to_input.c) \
		$(addprefix $(PATH_TOOL),\
		ft_calloc.c \
		ft_count_words.c \
		ft_is_whitespace.c \
		ft_minishell_exit.c \
		ft_free.c \
		ft_free_matrix.c \
		ft_free_tokens.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_test_tools.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I $(PATH_INCS) -I /usr/local/Cellar/readline/8.2.1/include/

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) -L/usr/local/Cellar/readline/8.2.1/lib -lreadline

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)exec/
	@mkdir -p $(PATH_OBJS)builtins/
	@mkdir -p $(PATH_OBJS)parser/
	@mkdir -p $(PATH_OBJS)prompt/
	@mkdir -p $(PATH_OBJS)init/
	@mkdir -p $(PATH_OBJS)tools/
	@mkdir -p $(PATH_OBJS)clean/
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

PHONY: all clean fclean re n r