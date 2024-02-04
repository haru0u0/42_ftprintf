/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 04:00:14 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/02/04 08:56:10 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_c(va_list args, int *count_ptr, const char ptr)
{
	int	nbr;

	if (ptr == 'c')
	{
		nbr = va_arg(args, int);
		ft_putchar_count(nbr, count_ptr);
	}
	else if (ptr == '%')
		ft_putchar_count('%', count_ptr);
}

void	ft_handle_str(va_list args, int *count_ptr)
{
	void	*generic_ptr;

	generic_ptr = va_arg(args, char *);
	if (generic_ptr == NULL)
		ft_putstr_count("(null)", count_ptr);
	else
		ft_putstr_count(generic_ptr, count_ptr);
}

void	ft_handle_ptr(va_list args, int *count_ptr)
{
	void			*generic_ptr;
	unsigned long	ul;

	generic_ptr = va_arg(args, void *);
	if (generic_ptr == NULL)
		ft_putstr_count("(nil)", count_ptr);
	else
	{
		ul = (unsigned long)generic_ptr;
		ft_putstr_count("0x", count_ptr);
		ft_puthex_lower(ul, count_ptr);
	}
}

void	ft_handle_diu(va_list args, int *count_ptr, const char ptr)
{
	int				nbr;
	unsigned int	ui;

	if (ptr == 'u')
	{
		ui = va_arg(args, unsigned int);
		ft_putunsigned_count(ui, count_ptr);
	}
	else if (ptr == 'i' || ptr == 'd')
	{
		nbr = va_arg(args, int);
		ft_putnbr_count(nbr, count_ptr);
	}
}

void	ft_handle_x(va_list args, int *count_ptr, const char ptr)
{
	unsigned int	ui;

	ui = va_arg(args, unsigned int);
	if (ptr == 'x')
		ft_puthex_lower(ui, count_ptr);
	else if (ptr == 'X')
		ft_puthex_upper(ui, count_ptr);
}
