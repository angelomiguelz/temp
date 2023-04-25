/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzarichn <mzarichn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:14:36 by mzarichn          #+#    #+#             */
/*   Updated: 2022/12/02 15:24:22 by mzarichn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"
# define DEC "0123456789"

typedef unsigned long long	t_ull;

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_varf(va_list args, const char varf);
int		ft_putnbr(long long nbr);
int		ft_putnbr_base(t_ull n, char *base, char c);

#endif