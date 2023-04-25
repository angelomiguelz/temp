/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:13:42 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/02 14:47:31 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DESCRIPTION
	   The memcpy() function copies n bytes from memory area src to
	   memory area dest.  The memory areas must not overlap.
RETURN VALUE
	   The memcpy() function returns a pointer to dest.
 */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
