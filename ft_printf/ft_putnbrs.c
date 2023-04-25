/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:43:43 by mzarichn          #+#    #+#             */
/*   Updated: 2022/12/05 15:58:15 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(t_ull n, char *base, char c)
{
	int		count;
	t_ull	baselen;

	baselen = ft_strlen(base);
	count = 0;
	if (c == 'p')
	{
		if (!n)
			return (ft_putstr("(nil)"));
		count = ft_putstr("0x");
		c = '0';
	}
	if (n >= baselen)
		count += ft_putnbr_base(n / baselen, base, c);
	return (write(1, &base[n % baselen], 1) + count);
}

int	ft_putnbr(long long nbr)
{
	int			count;

	count = 0;
	if (nbr < 0)
	{	
		nbr = -nbr;
		count += write(1, "-", 1);
	}
	return (count + ft_putnbr_base(nbr, DEC, 'd'));
}
