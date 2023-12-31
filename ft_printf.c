/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:15:12 by hsenzaki          #+#    #+#             */
/*   Updated: 2023/12/25 23:05:21 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <unistd.h>

void hex_upper (unsigned long ul, int *count_ptr)
{
	if (ul >= 16)
	{
		hex_upper (ul / 16, count_ptr);
		hex_upper (ul % 16, count_ptr);
	}
	else
	{
		*count_ptr = *count_ptr + 1;
		if (ul <= 9)
			ft_putnbr_fd((int)ul, 1);
		else
			ft_putchar_fd('A' + (ul - 10),1);
	}
}

void hex_lower (unsigned long ul, int *count_ptr)
{
	if (ul >= 16)
	{
		hex_lower (ul / 16, count_ptr);
		hex_lower (ul % 16, count_ptr);
	}
	else
	{
		*count_ptr = *count_ptr + 1;
		if (ul <= 9)
			ft_putnbr_fd((int)ul, 1);
		else
			ft_putchar_fd('a' + (ul - 10),1);
	}
}

void	ft_putnbr_count (int n, int *count_ptr)
{
	char	chara;

	if (n < 0)
	{
		if (n == INT_MIN)
		{
			write (1, "-2147483648", 11);
			*count_ptr = 11;
			return ;
		}
		n = n * -1;
		write (1, &"-", 1);
		*count_ptr = 1;
	}
	if (n > 9)
	{
		ft_putnbr_count(n / 10, count_ptr);
		ft_putnbr_count(n % 10, count_ptr);
	}
	else
	{
		chara = n + '0';
		write(1, &chara, 1);
		*count_ptr = *count_ptr + 1;
	}
}

int ft_printf(const char *ptr, ...)
{
	va_list	args;
	char	chara;
	char	*str;
	int		nbr;
	void	*point;
	unsigned long	ul;
	int		count;
	int		*count_ptr;
	int		dummy;

	count = 0;
	va_start (args, ptr);
	dummy = 0;
	count_ptr = &dummy;

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			*count_ptr = 0;
			if (*ptr == 'c')
			{
				chara = va_arg (args, int);
				ft_putchar_fd (chara, 1);
				count++;
			}
			else if (*ptr == 's')
			{
				str = va_arg (args, char *);
				if (str == NULL)
					str = "(null)";
				ft_putstr_fd (str, 1);
				count = count + ft_strlen(str);
			}
			else if (*ptr == 'p')
			{
				point = va_arg (args, void *);
				ul = (unsigned long)point;
				ft_putstr_fd("0x", 1);
				hex_lower(ul, count_ptr);
				count = count + *count_ptr + 2;
			}
			else if (*ptr == 'd' || *ptr == 'i')
			{
				nbr = va_arg (args, int);
				ft_putnbr_count (nbr, count_ptr);
				count = count + *count_ptr;
			}
			else if (*ptr == 'u')
			{
				ul = va_arg (args, unsigned long);
				ft_putnbr_count (ul, count_ptr);
				count = count + *count_ptr;
			}
			else if (*ptr == 'x')
			{
				ul = va_arg (args, unsigned long);
				hex_lower (ul, count_ptr);
				count = count + *count_ptr;
			}
			else if (*ptr == 'X')
			{
				ul = va_arg (args, unsigned long);
				hex_upper (ul, count_ptr);
				count = count + *count_ptr;
			}
			else if (*ptr == '%')
			{
				ft_putchar_fd ('%', 1);
				count++;
			}
		}
		else
		{
			chara = *ptr;
			ft_putchar_fd (chara, 1);
			count++;
		}
		ptr++;
	}
	va_end (args);
	return (count);
}
