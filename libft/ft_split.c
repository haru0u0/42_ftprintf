/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 05:14:10 by hsenzaki          #+#    #+#             */
/*   Updated: 2023/12/05 02:25:41 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countrow(char const *s, char c)
{
	int	sdx;
	int	row;

	sdx = 0;
	row = 0;
	while (sdx < (int)ft_strlen(s))
	{
		if (s[sdx] == c)
		{
			row++;
			while (s[sdx] == c)
				sdx++;
		}
		else
			sdx++;
	}
	if (s[sdx - 1] != c)
		row++;
	return (row);
}

bool	empty(char const *s, char c)
{
	if (*s == '\0')
		return (true);
	while (*s != '\0')
	{
		if (*s != c)
			return (false);
		s++;
	}
	return (true);
}

char	**ftcolumn(char const *s, char c, char **dest)
{
	int	sdx;
	int	adx;
	int	column;

	sdx = 0;
	adx = 0;
	column = 0;
	while (adx < countrow(s, c))
	{
		while (s[sdx] != c && s[sdx] != '\0')
		{
			column++;
			sdx++;
		}
		dest[adx] = malloc((column + 1) * sizeof(char));
		if (dest[adx] == NULL)
			return (NULL);
		while (s[sdx] == c)
			sdx++;
		adx++;
		column = 0;
	}
	dest[adx] = NULL;
	return (dest);
}

void	putsplit(char const *s, char c, char **dest)
{
	int	adx;
	int	cdx;

	adx = 0;
	cdx = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			dest[adx][cdx] = *s;
			cdx++;
			s++;
		}
		else if (*s == c)
		{
			dest[adx][cdx] = '\0';
			adx++;
			cdx = 0;
			while (*s == c)
				s++;
		}
	}
	if (*(s - 1) != c)
		dest[adx][cdx] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	char	**column;

	if (empty(s, c) == true)
	{
		dest = malloc(1 * sizeof(char *));
		dest[0] = NULL;
		return (dest);
	}
	while (*s == c)
		s++;
	dest = malloc((countrow(s, c) + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	column = ftcolumn(s, c, dest);
	if (column == NULL)
	{
		free (dest);
		return (NULL);
	}
	putsplit (s, c, dest);
	return (dest);
}
