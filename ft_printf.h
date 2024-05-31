/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 01:37:51 by nilamber          #+#    #+#             */
/*   Updated: 2024/05/31 21:15:07 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_dui(va_list arg_v);
int		ft_hex(va_list argv, const char c);
size_t	ft_strlen(const char *s);
int		ft_arg_filter(const char *str, va_list arg_v);
int		ft_arg_redirector(const char c, va_list arg_v);
int		ft_arg_count(const char *str);
int		ft_deci_count(long long num);
int		ft_putnbr_hx(unsigned long num, int m);
int		ft_putstr(char *str);
void	*ft_calloc(size_t nitems, size_t size);

#endif