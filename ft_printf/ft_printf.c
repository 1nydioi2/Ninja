/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 01:24:13 by nilamber          #+#    #+#             */
/*   Updated: 2024/05/24 02:21:25 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_deci_count(long long i)
{
	int	count;

	count = 1;
	while (i > 9)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

int	ft_arg_count(const char *str)
{
	int	count;

	count = 0;
	while (*str)
		if (*str++ == '%')
			count++;
	return (count);
}

int	ft_arg_redirector(const char c, va_list arg_v)
{
	if (c == 'd' || c == 'i' || c == 'u')
		count_w = ft_dui(arg_v);
	else if (c == 'X' || c == 'x' || c == 'p')
		count_w = ft_hex(arg_v);
	else if (c == 's')
		write(1, )
		count_w = ft_str(arg_v);
	else if (c == '%' || c == 'c')
	{
		write(1, &va_arg(arg_v, char), 1);
		count_w = 1;
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
			count_w += ft_arg_redirector(str[i], va_arg(argv, void *));
		}
		else
		{
			write(1, &str[i], 1);
			count_w++;
		}
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	int	count_w;
	int	arg_n;
	va_list	arg_v;

	arg_n = ft_arg_count(str);
	va_start(arg_v, arg_n);
	count_w = ft_arg_filter(str, arg_v);
	va_end(arg_v);
	return (count_w);
}
