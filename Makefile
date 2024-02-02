NAME    = libftprintf.a
SRCS    = ft_printf.c
OBJS    = ft_printf.o

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(LIBFT)
	cc -Wall -Wextra -Werror -c -o ft_printf.o ft_printf.c

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all
