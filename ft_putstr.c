/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:10:42 by nilamber          #+#    #+#             */
/*   Updated: 2024/06/04 14:46:35 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (str[i])
		i++;
	while (--i > -1)
		ret += write(1, &str[i], 1);
	return (ret);
}
