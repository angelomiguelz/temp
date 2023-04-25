/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:52:28 by mzarichn          #+#    #+#             */
/*   Updated: 2022/10/26 16:39:07 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPTION
	   The memset() function fills the first n bytes of the memory area
	   pointed to by s with the constant byte c.
RETURN VALUE
	   The memset() function returns a pointer to the memory area s.
 */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
