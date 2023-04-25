/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:56:00 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/13 15:41:43 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Allocates (with malloc) and returns a string representing the integer 
*	received as an argument. Negative numbers must be handled.
*	PARAMETERS
*	#1. the integer to convert.
*	RETURN VALUES
*	The string representing the integer. NULL if the allocation fails.
*/

#include "libft.h"
#include <stdlib.h>

int	ft_countlen(int n)
{
	int	c;

	c = 0;
	if (n <= 0)
		c++;
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	numb;

	numb = n;
	len = ft_countlen(numb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (numb < 0)
	{
		str[0] = '-';
		numb *= -1;
	}
	if (numb == 0)
		str[0] = '0';
	str[len] = '\0';
	len--;
	while (numb)
	{
		str[len] = numb % 10 + '0';
		len--;
		numb /= 10;
	}
	return (str);
}
