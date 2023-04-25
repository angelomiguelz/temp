/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:50:29 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/13 15:17:30 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !(sub))
		return (0);
	i = 0;
	while (start < (unsigned int)ft_strlen((char *)s) && i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
