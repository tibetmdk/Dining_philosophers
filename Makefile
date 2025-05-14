cc = CC

CFLAGS = -Wall -Wextra -Werror

NAME = philosophers

SRCS = dinner.c init.c main.c monitor.c parsing.c threads.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lpthread $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re