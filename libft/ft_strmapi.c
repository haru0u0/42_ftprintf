/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:05:50 by hsenzaki          #+#    #+#             */
/*   Updated: 2023/11/20 02:23:49 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		dx;
	char	*dest;
	char	*dest_cpy;

	dx = 0;
	dest = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}
	dest_cpy = dest;
	while (s[dx] != '\0')
	{
		*dest = f(dx, s[dx]);
		dest++;
		dx++;
	}
	*dest = '\0';
	return (dest_cpy);
}
