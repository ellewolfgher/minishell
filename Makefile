NAME = minishell

PATH_INCS = ./includes/
PATH_LIBS = ./libft/
PATH_OBJS = ./objects/
PATH_SRCS = ./sources/
PATH_EXEC = $(PATH_SRCS)execution/
PATH_PARS = $(PATH_SRCS)parser/

SRCS = $(addprefix $(PATH_SRCS),\
		ft_main.c)\
		$(addprefix $(PATH_EXEC),\
		ft_execution.c)\
		$(addprefix $(PATH_PARS),\
		ft_parser.c)

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
	@mkdir -p $(PATH_OBJS)execution/
	@mkdir -p $(PATH_OBJS)parser/
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# $(LIBFT):
# 	@make -C $(PATH_LIBS)

clean:
	@rm -rf $(PATH_OBJS)

fclean: clean
	@rm $(NAME)

re: fclean all

r: all
	@./minishell
n:
	@clear
	@norminette ./sources ./includes

PHONY: all clean fclean re n r