/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:34:44 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/02 20:48:11 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ps;

	ps = (char *)s;
	i = 0;
	while (i <= (int)ft_strlen(ps))
	{
		if (ps[i] == (char)c)
			return (&ps[i]);
		i++;
	}
	return (0);
}
