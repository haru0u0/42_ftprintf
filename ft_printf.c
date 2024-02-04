/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:15:12 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/02/04 08:56:46 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	handle_format(va_list args, int *count_ptr, const char *ptr)
{
	if (*ptr == 'c' || *ptr == '%')
		ft_handle_c(args, count_ptr, *ptr);
	else if (*ptr == 's')
		ft_handle_str(args, count_ptr);
	else if (*ptr == 'p')
		ft_handle_ptr(args, count_ptr);
	else if (*ptr == 'd' || *ptr == 'i' || *ptr == 'u')
		ft_handle_diu(args, count_ptr, *ptr);
	else if (*ptr == 'x' || *ptr == 'X')
		ft_handle_x(args, count_ptr, *ptr);
}

int	ft_printf(const char *ptr, ...)
{
	va_list	args;
	int		count_ptr;

	count_ptr = 0;
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
