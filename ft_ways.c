/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 02:08:32 by nilamber          #+#    #+#             */
/*   Updated: 2024/06/04 14:39:38 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dui(va_list arg_v)
{
	int			count_w;
	long int	num;
	int			power[2];
	char		str[32];
	int			i;

	i = 0;
	num = va_arg(arg_v, int);
	if (num < 0)
	{
		count_w = write(1, "-", 1);
		num = -num;
	}
	ft_bzero(str, 32);
	while (num > 9)
	{
		power[0] = ft_deci_count(num);
		power[1] = 1;
		while (--power[0])
			power[1] *= 10;
		str[i++] = ((num % power[1]) + 48);
		num /= 10;
	}
	str[i++] = (num + 48);
	count_w += ft_putstr(str);
	return (count_w);
}

int	ft_hex(va_list arg_v, const char c)
{
	int					count_w;
	unsigned long long	ptr;

	count_w = 0;
	if (c == 'X')
		count_w = ft_putnbr_hx(va_arg(arg_v, unsigned long long), 1);
	else if (c == 'x')
		count_w = ft_putnbr_hx(va_arg(arg_v, unsigned long long), 0);
	else if (c == 'p')
	{
		ptr = va_arg(arg_v, unsigned long long);
		if (ptr == 0)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + ft_putnbr_hx(ptr, 0));
	}
	return (count_w);
}

int	ft_putnbr_hx(unsigned long num, int m)
{
	char	str[15];
	int		count_w;
	char	*base[2];
	int		i;

	base[0] = "0123456789abcdef";
	base[1] = "0123456789ABCDEF";
	i = 0;
	count_w = 0;
	while (num >= 16)
	{
		str[i] = base[m][(num % 16)];
		num /= 16;
		i++;
	}
	str[i++] = base[m][(num % 16)];
	while (--i >= 0)
	{
		write(1, &str[i], 1);
		count_w++;
	}
	return (count_w);
}
