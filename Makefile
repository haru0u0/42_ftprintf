NAME    = libftprintf.a
SRCS    = ft_printf.c utils1.c utils2.c handlers.c
OBJS    = $(SRCS:.c=.o)
CFLAGS  = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all