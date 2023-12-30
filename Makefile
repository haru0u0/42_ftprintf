NAME    = libftprintf.a
SRCS    = ft_printf.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_strlen.c
OBJS    = ft_printf.o libft/ft_putchar_fd.o libft/ft_putstr_fd.o libft/ft_putnbr_fd.o libft/ft_strlen.o
CFLAGS  = -Wall -Wextra -Werror
LIBFT	= libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(LIBFT)
	cc -Wall -Wextra -Werror -c -o ft_printf.o ft_printf.c -L. -lft

$(LIBFT):
	make -C libft
	cp libft/libft.h .
	cp libft/libft.a .

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all
