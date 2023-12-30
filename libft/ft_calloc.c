/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:08:21 by hsenzaki          #+#    #+#             */
/*   Updated: 2023/12/04 00:38:33 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*mem;

	if (size == 0 || nmemb == 0)
	{
		size = 1;
		nmemb = 1;
	}
	bytes = nmemb * size;
	if (bytes / size != nmemb)
	{
		return (NULL);
	}
	mem = malloc(size * nmemb);
	if (mem == NULL)
	{
		return (NULL);
	}
	ft_memset(mem, 0, size * nmemb);
	return (mem);
}
