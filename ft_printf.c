/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:15:12 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/02/02 16:38:20 by hsenzaki         ###   ########.fr       */
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
			ft_putchar_count('A' + (ul - 10), count_ptr);
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
			ft_putchar_count('a' + (ul - 10), count_ptr);
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
		ft_putchar_count('-', count_ptr);
	}
	if (n > 9)
	{
		ft_putnbr_count(n / 10, count_ptr);
		ft_putnbr_count(n % 10, count_ptr);
	}
	else
		ft_putchar_count(n + '0', count_ptr);
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
		ft_putchar_count(n + '0', count_ptr);
}

void ft_putchar_count(char c, int *count_ptr)
{
	write(1, &c, 1);
	*count_ptr = *count_ptr + 1;
}

void ft_putstr_count(char *s, int *count_ptr)
{
	int len;

	len = ft_strlen(s);
	write(1, s, len);
	*count_ptr = *count_ptr + ft_strlen(s);
}

void ft_handle_c(va_list args, int *count_ptr, const char ptr)
{
	int nbr;

	if (ptr == 'c')
	{
		nbr = va_arg(args, int);
		ft_putchar_count(nbr, count_ptr);
	}
	else if (ptr == '%')
		ft_putchar_count('%', count_ptr);
}

void ft_handle_str(va_list args, int *count_ptr)
{
	void *generic_ptr;

	generic_ptr = va_arg(args, char *);
	if (generic_ptr == NULL)
		ft_putstr_count("(null)", count_ptr);
	else
		ft_putstr_count(generic_ptr, count_ptr);
}

void ft_handle_ptr(va_list args, int *count_ptr)
{
	void *generic_ptr;

	generic_ptr = va_arg(args, void *);
	if (generic_ptr == NULL)
		ft_putstr_count("(nil)", count_ptr);
	else
	{
		ft_putstr_count("0x", count_ptr);
		hex_lower((unsigned long)generic_ptr, count_ptr);
	}
}

void ft_handle_di(va_list args, int *count_ptr)
{
	int nbr;

	nbr = va_arg(args, int);
	ft_putnbr_count(nbr, count_ptr);
}

void ft_handle_u(va_list args, int *count_ptr)
{
	long long ll;

	ll = va_arg(args, long long);
	ft_putunsigned_count(ll, count_ptr);
}

void ft_handle_x(va_list args, int *count_ptr, const char ptr)
{
	unsigned long ul;

	ul = va_arg(args, unsigned long);
	if (ptr == 'x')
		hex_lower(ul, count_ptr);
	else if (ptr == 'X')
		hex_upper(ul, count_ptr);
}

void handle_format(va_list args, int *count_ptr, const char *ptr)
{
	if (*ptr == 'c' || *ptr == '%')
		ft_handle_c(args, count_ptr, *ptr);
	else if (*ptr == 's')
		ft_handle_str(args, count_ptr);
	else if (*ptr == 'p')
		ft_handle_ptr(args, count_ptr);
	else if (*ptr == 'd' || *ptr == 'i')
		ft_handle_di(args, count_ptr);
	else if (*ptr == 'u')
		ft_handle_u(args, count_ptr);
	else if (*ptr == 'x' || *ptr == 'X')
		ft_handle_x(args, count_ptr, *ptr);
}

int ft_printf(const char *ptr, ...)
{
	va_list args;
	int count_ptr;
	va_start(args, ptr);

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			handle_format(args, &count_ptr, ptr);
		}
		else
			ft_putchar_count(*ptr, &count_ptr);
		ptr++;
	}
	va_end(args);
	return (count_ptr);
}
