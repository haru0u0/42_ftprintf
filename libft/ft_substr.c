/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:27:10 by hsenzaki          #+#    #+#             */
/*   Updated: 2023/12/04 01:02:26 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*memory(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (start >= ft_strlen(s))
	{
		dest = malloc(1);
	}
	else if (ft_strlen(s) - start < len)
	{
		dest = malloc ((ft_strlen(s) - start) + 1);
	}
	else if (len > (size_t)ft_strlen(s))
	{
		dest = malloc(ft_strlen(s) + 1);
	}
	else
	{
		dest = malloc(len + 1);
	}
	return (dest);
}

void	copy(char const *s, unsigned int start, size_t len, char *dest)
{
	while (start != 0)
	{
		s++;
		start--;
	}
	while (*s != '\0' && len != 0)
	{
		*dest = *s;
		s++;
		dest++;
		len--;
	}
	*dest = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (s == NULL)
	{
		return (NULL);
	}
	dest = memory(s, start, len);
	if (start >= ft_strlen(s))
	{
		*dest = '\0';
		return (dest);
	}
	if (dest == NULL)
	{
		return (NULL);
	}
	copy(s, start, len, dest);
	return (dest);
}
