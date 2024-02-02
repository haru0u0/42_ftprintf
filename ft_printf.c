/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:15:12 by hsenzaki          #+#    #+#             */
/*   Updated: 2023/12/30 21:58:18 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s != 0)
	{
		i++;
		s++;
	}
	return (i);
}

void hex_upper(unsigned long ul, int *count_ptr)
{
	if (ul >= 16)
	{
		hex_upper(ul / 16, count_ptr);
		hex_upper(ul % 16, count_ptr);
	}
	else
	{
		if (ul <= 9)
			ft_putnbr_count((int)ul, count_ptr);
		else
			ft_putchar_fd('A' + (ul - 10), 1, count_ptr);
	}
}

void hex_lower(unsigned long ul, int *count_ptr)
{
	if (ul >= 16)
	{
		hex_lower(ul / 16, count_ptr);
		hex_lower(ul % 16, count_ptr);
	}
	else
	{
		if (ul <= 9)
			ft_putnbr_count((int)ul, count_ptr);
		else
			ft_putchar_fd('a' + (ul - 10), 1, count_ptr);
	}
}

void ft_putnbr_count(int n, int *count_ptr)
{
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			write(1, "-2147483648", 11);
			*count_ptr = *count_ptr + 11;
			return;
		}
		n = n * -1;
		ft_putchar_fd('-', 1, count_ptr);
	}
	if (n > 9)
	{
		ft_putnbr_count(n / 10, count_ptr);
		ft_putnbr_count(n % 10, count_ptr);
	}
	else
		ft_putchar_fd(n + '0', 1, count_ptr);
}

void ft_putunsigned_count(long long n, int *count_ptr)
{
	if (n < 0)
	{
		n = 4294967296 + n;
		*count_ptr = 1;
	}
	if (n > 9)
	{
		ft_putunsigned_count(n / 10, count_ptr);
		ft_putunsigned_count(n % 10, count_ptr);
	}
	else
		ft_putchar_fd(n + '0', 1, count_ptr);
}

void ft_putchar_fd(char c, int fd, int *count_ptr)
{
	write(fd, &c, 1);
	*count_ptr = *count_ptr + 1;
}

void ft_putstr_fd(char *s, int fd, int *count_ptr)
{
	int len;

	len = ft_strlen(s);
	write(fd, s, len);
	*count_ptr = *count_ptr + ft_strlen(s);
}

int ft_printf(const char *ptr, ...)
{
	va_list args;
	int *count_ptr;
	int dummy;
	void *input;
	va_start(args, ptr);
	dummy = 0;
	count_ptr = &dummy;

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
				ft_putchar_fd(va_arg(args, int), 1, count_ptr);
			else if (*ptr == 's')
			{
				input = va_arg(args, char *);
				if (input == NULL)
					input = "(null)";
				ft_putstr_fd((char *)input, 1, count_ptr);
			}
			else if (*ptr == 'p')
			{
				input = va_arg(args, void *);
				if (input == NULL)
					ft_putstr_fd("(nil)", 1, count_ptr);
				else
				{
					ft_putstr_fd("0x", 1, count_ptr);
					hex_lower((unsigned long)input, count_ptr);
				}
			}
			else if (*ptr == 'd' || *ptr == 'i')
				ft_putnbr_count(va_arg(args, int), count_ptr);
			else if (*ptr == 'u')
				ft_putunsigned_count(va_arg(args, long long), count_ptr);
			else if (*ptr == 'x')
				hex_lower(va_arg(args, unsigned long), count_ptr);
			else if (*ptr == 'X')
				hex_upper(va_arg(args, unsigned long), count_ptr);
			else if (*ptr == '%')
				ft_putchar_fd('%', 1, count_ptr);
		}
		else
			ft_putchar_fd(*ptr, 1, count_ptr);
		ptr++;
	}
	va_end(args);
	return (*count_ptr);
}
