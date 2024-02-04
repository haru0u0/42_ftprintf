/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 03:59:13 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/02/04 08:54:27 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_upper(unsigned long ul, int *count_ptr)
{
	if (ul >= 16)
	{
		ft_puthex_upper(ul / 16, count_ptr);
		ft_puthex_upper(ul % 16, count_ptr);
	}
	else
	{
		if (ul <= 9)
			ft_putnbr_count((int)ul, count_ptr);
		else
			ft_putchar_count('A' + (ul - 10), count_ptr);
	}
}

void	ft_puthex_lower(unsigned long ui, int *count_ptr)
{
	if (ui >= 16)
	{
		ft_puthex_lower(ui / 16, count_ptr);
		ft_puthex_lower(ui % 16, count_ptr);
	}
	else
	{
		if (ui <= 9)
			ft_putnbr_count((int)ui, count_ptr);
		else
			ft_putchar_count('a' + (ui - 10), count_ptr);
	}
}

void	ft_putnbr_count(int n, int *count_ptr)
{
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			write(1, "-2147483648", 11);
			*count_ptr = *count_ptr + 11;
			return ;
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

void	ft_putunsigned_count(unsigned int n, int *count_ptr)
{
	if (n > 9)
	{
		ft_putunsigned_count(n / 10, count_ptr);
		ft_putunsigned_count(n % 10, count_ptr);
	}
	else
		ft_putchar_count(n + '0', count_ptr);
}
