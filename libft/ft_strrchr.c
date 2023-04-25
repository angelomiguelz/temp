/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:53:26 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/10 15:49:00 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = ft_strlen((char *)str);
	s = (char *)str;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i--;
	}
	return (NULL);
}
