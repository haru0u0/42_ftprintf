/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 03:59:41 by hsenzaki          #+#    #+#             */
/*   Updated: 2024/02/04 08:55:15 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count(char c, int *count_ptr)
{
	write(1, &c, 1);
	*count_ptr = *count_ptr + 1;
}

void	ft_putstr_count(char *s, int *count_ptr)
{
	int	len;

	len = ft_strlen(s);
	write(1, s, len);
	*count_ptr = *count_ptr + ft_strlen(s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != 0)
	{
		i++;
		s++;
	}
	return (i);
}
