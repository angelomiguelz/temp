/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:53:31 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/03 14:51:02 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	s = (char *)malloc(sizeof(char) * len);
	if (!s)
		return (0);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	j = 0;
	while (s2[j])
		s[i++] = s2[j++];
	s[i] = 0;
	return (s);
}
