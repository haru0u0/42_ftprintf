/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:06:35 by hsenzaki          #+#    #+#             */
/*   Updated: 2023/12/04 19:26:39 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	long_dest(size_t count,
		size_t size, char *dest, const char *src)
{
	while (*src != '\0' && size - 1 > count)
	{
		*dest = *src;
		dest++;
		src++;
		count++;
	}
	while (*src != '\0')
	{
		src++;
		count++;
	}
	*dest = '\0';
	return (count);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (dst == NULL && size == 0)
	{
		return (0);
	}
	while (*dst != '\0' && count < size)
	{
		dst++;
		count++;
	}
	if (count >= size)
	{
		return (size + ft_strlen(src));
	}
	else if (count < size)
	{
		count = long_dest (count, size, dst, src);
	}
	return (count);
}
