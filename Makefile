NAME = minishell

PATH_INCS = ./includes/
PATH_LIBS = ./libft/
PATH_OBJS = ./objects/
PATH_SRCS = ./sources/
PATH_EXEC = $(PATH_SRCS)exec/
PATH_BUIL = $(PATH_SRCS)builtins/
PATH_PARS = $(PATH_SRCS)parser/
PATH_INTR = $(PATH_SRCS)interactive/
PATH_INIT = $(PATH_SRCS)init/
PATH_TOOL = $(PATH_SRCS)tools/

SRCS = $(addprefix $(PATH_SRCS),\
		ft_main.c) \
		$(addprefix $(PATH_EXEC),\
		ft_executioner.c) \
		$(addprefix $(PATH_BUIL),\
		ft_cd.c \
		ft_pwd.c \
		ft_export.c \
		ft_echo.c \
		ft_env.c \
		ft_unset.c) \
		$(addprefix $(PATH_PARS),\
		ft_parser.c) \
		$(addprefix $(PATH_INIT),\
		ft_global_init.c \
		ft_minishell_init.c) \
		$(addprefix $(PATH_INTR),\
		ft_handle_interactive_signals.c \
		ft_initiate_interactive_signals.c)\
		$(addprefix $(PATH_TOOL),\
		ft_calloc.c \
		ft_test_tools.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

# LIBFT = $(PATH_LIBS)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(PATH_INCS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) -lreadline

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)exec/
	@mkdir -p $(PATH_OBJS)builtins/
	@mkdir -p $(PATH_OBJS)parser/
	@mkdir -p $(PATH_OBJS)interactive/
	@mkdir -p $(PATH_OBJS)init/
	@mkdir -p $(PATH_OBJS)tools/
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# $(LIBFT):
# 	@make -C $(PATH_LIBS)

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