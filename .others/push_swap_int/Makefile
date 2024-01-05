NAME = push_swap.a
SRCS = commands.c utils.c push_swap.c 
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./ft_printf clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libft fclean
	$(MAKE) -C ./ft_printf fclean

re: fclean all

.PHONY: all clean fclean re
