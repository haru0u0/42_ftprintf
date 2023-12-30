/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:58:45 by hsenzaki          #+#    #+#             */
/*   Updated: 2023/12/04 19:58:00 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	dx;
	char	*dest_cpy;
	char	*src_cpy;

	dx = 0;
	dest_cpy = (char *)dest;
	src_cpy = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
	{
		while (dx < n)
		{
			dest_cpy [dx] = src_cpy [dx];
			dx++;
		}
	}
	else if (dest > src)
	{
		while (n--)
		{
			dest_cpy[n] = src_cpy[n];
		}
	}
	return (dest);
}
