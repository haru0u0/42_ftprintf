/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <hsenzaki@student.42.uk>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:18:58 by hsenzaki          #+#    #+#             */
/*   Updated: 2023/12/04 19:09:04 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	trimlen(char const *start, char const *end)
{
	int	count;

	count = 0;
	while (start != end + 1)
	{
		count++;
		start++;
	}
	return (count);
}

char const	*lastcharacter(char const *s1, char const *set)
{
	int			s1dx;
	int			setdx;
	bool		ismatched;

	s1dx = 0;
	setdx = 0;
	ismatched = false;
	while (s1[s1dx] != 0)
		s1dx++;
	s1dx--;
	while (s1dx >= 0)
	{
		while (set[setdx] != 0)
		{
			if (s1[s1dx] == set[setdx])
				ismatched = true;
			setdx++;
		}
		if (ismatched == false)
			return (s1 + s1dx);
		ismatched = false;
		s1dx--;
		setdx = 0;
	}
	return (s1 + s1dx);
}

char const	*firstcharacter(char const *s1, char const *set)
{
	char const	*set_cpy;
	bool		ismatched;

	set_cpy = set;
	ismatched = false;
	while (*s1 != 0)
	{
		while (*set != 0)
		{
			if (*s1 == *set)
			{
				ismatched = true;
			}
			set++;
		}
		if (ismatched == false)
		{
			return (s1);
		}
		set = set_cpy;
		ismatched = false;
		s1++;
	}
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*dest;
	char		*dest_cpy;
	char const	*start;
	char const	*end;

	start = firstcharacter(s1, set);
	if (*start == '\0')
	{
		dest = malloc(sizeof(char));
		*dest = '\0';
		return (dest);
	}
	end = lastcharacter(s1, set);
	dest = malloc((trimlen(start, end) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest_cpy = dest;
	while (start != end + 1)
	{
		*dest = *((char *)start);
		start++;
		dest++;
	}
	*dest = '\0';
	return (dest_cpy);
}
