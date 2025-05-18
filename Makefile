cc = CC

CFLAGS = -Wall -Wextra -Werror

NAME = philo

SRCS = src/dinner.c src/init.c src/main.c src/monitor.c src/parsing.c src/threads.c src/utils.c src/clean_all.c

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