/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenzaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:50:26 by hsenzaki          #+#    #+#             */
/*   Updated: 2023/12/05 00:31:59 by hsenzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	calcdigit(int digit, int n)
{
	while (n != 0)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

char	*putitoa(char *dest, int n, bool isnegative)
{
	*dest = '\0';
	dest--;
	while (n != 0)
	{
		*dest = (n % 10) + '0';
		n = n / 10;
		dest--;
	}
	if (isnegative == true)
		*dest = '-';
	else
		dest++;
	return (dest);
}

char	*zero(void)
{
	char	*dest;

	dest = malloc(2 * sizeof(char));
	if (dest == NULL)
		return (NULL);
	else
		ft_strlcpy (dest, "0", 2);
	return (dest);
}

char	*intmin(void)
{
	char	*dest;

	dest = malloc(12 * sizeof(char));
	if (dest == NULL)
		return (NULL);
	else
		ft_strlcpy (dest, "-2147483648", 12);
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		digit;
	bool	isnegative;

	digit = 0;
	isnegative = false;
	if (n == -2147483648)
		return (intmin());
	else if (n == 0)
		return (zero());
	else if (n < 0)
	{
		isnegative = true;
		digit = 1;
		n = n * -1;
	}
	digit = calcdigit (digit, n);
	dest = malloc((digit + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest = dest + digit;
	return (putitoa (dest, n, isnegative));
}
