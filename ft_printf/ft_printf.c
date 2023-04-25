/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:11:39 by mzarichn          #+#    #+#             */
/*   Updated: 2022/11/23 13:55:41 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		p_len;

	i = 0;
	p_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			p_len += ft_varf(args, str[i + 1]);
			i++;
		}
		else
			p_len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (p_len);
}
