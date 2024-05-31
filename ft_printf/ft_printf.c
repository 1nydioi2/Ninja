/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 01:24:13 by nilamber          #+#    #+#             */
/*   Updated: 2024/05/30 18:39:26 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_deci_count(long long num)
{
	int	count;

	count = 1;
	if (num < 0)
		num = -num;
	while (num > 9)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	ft_arg_redirector(const char c, va_list arg_v)
{
	int	count_w;
	char	*str;
	char	c2;

	count_w = 0;
	if (c == 'd' || c == 'i' || c == 'u')
		count_w += ft_dui(arg_v);
	else if (c == 'X' || c == 'x' || c == 'p')
		count_w = ft_hex(arg_v, c);
	else if (c == 's')
	{
		str = va_arg(arg_v, char *);
		if (str == NULL)
			return(write(1, "(null)", 6));
		write(1, str, ft_strlen(str));
		count_w += ft_strlen(str);
	}
	else if (c == '%' || c == 'c')
	{
		c2 = va_arg(arg_v, int);
		write(1, &c2, 1);
		count_w ++;
	}
	return (count_w);
}

int	ft_arg_filter(const char *str, va_list arg_v)
{
	int	i;
	int	count_w;

	i = 0;
	count_w = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count_w += ft_arg_redirector(str[i], arg_v);
		}
		else
		{
			write(1, &str[i], 1);
			count_w++;
		}
		i++;
	}
	return (count_w);
}

int	ft_printf(const char *str, ...)
{
	int	count_w;
	va_list	arg_v;

	va_start(arg_v, str);
	count_w = ft_arg_filter(str, arg_v);
	va_end(arg_v);
	return (count_w);
}
