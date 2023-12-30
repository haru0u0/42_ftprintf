/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:05:36 by hsenzaki          #+#    #+#             */
/*   Updated: 2023/12/04 19:37:16 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*dup_cpy;

	dup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup == NULL)
	{
		return (NULL);
	}
	dup_cpy = dup;
	while (*s != '\0')
	{
		*dup = *s;
		dup++;
		s++;
	}
	*dup = '\0';
	return (dup_cpy);
}
