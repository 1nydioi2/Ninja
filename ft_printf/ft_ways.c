/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 02:08:32 by nilamber          #+#    #+#             */
/*   Updated: 2024/05/30 19:28:09 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dui(va_list arg_v)
{
	int			count_w;
	long int	num;
	int			power[2];
	char		c;

	num = va_arg(arg_v, long int);
	count_w = (num < 0);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	while (ft_deci_count(num) > 1)
	{
		power[1] = 1;
		*power = ft_deci_count(num);
		while (--power[0])
			power[1] *= 10;
		c = ((num / power[1]) + 48);
		write(1, &c, 1);
		count_w++;
		c = ((num % power[1]) + 48);
		num %= power[1];
	}
	return (count_w + write(1, &c, 1));
}

int	ft_hex(va_list arg_v, const char c)
{
	int		count_w;

	count_w = 0;
	if (c == 'X')
		count_w = ft_putnbr_hx(va_arg(arg_v, unsigned int), 1);
	else if (c == 'x')
		count_w = ft_putnbr_hx(va_arg(arg_v, unsigned int), 0);
	return (count_w);
}

int	ft_putnbr_hx(unsigned long num, int m)
{
	char	str[15];
	int		count_w;
	char	*base[2];
	int		i;

	base[0] = "00123456789abcdef";
	base[1] = "00123456789ABCDEF";
	i = 0;
	count_w = 0;
	while (num >= 16)
	{
		str[i] = base[m][(num % 16)];
		num /= 16;
		i++;
	}
	while (--i >= 0)
	{
		write(1, &str[i], 1);
		count_w++;
	}
	return (count_w);
}
