/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_varf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:37:52 by mzarichn          #+#    #+#             */
/*   Updated: 2022/12/02 15:32:30 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_varf(va_list args, const char varf)
{
	if (varf == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (varf == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (varf == 'p')
		return (ft_putnbr_base((va_arg(args, long long)), HEXA_LOW, 'p'));
	else if (varf == 'd' || varf == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (varf == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (varf == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), HEXA_LOW, 'x'));
	else if (varf == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), HEXA_UP, 'X'));
	else if (varf == '%')
		return (ft_putchar('%'));
	return (0);
}
