/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:39:35 by nilamber          #+#    #+#             */
/*   Updated: 2024/05/31 20:01:39 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	size_t	i;
	int		d;

	d = 100000;
	i = printf("printf = %d\t", d);
	printf("printf = %zu\n", i);
	i = ft_printf("ft_printf = %d", d);
	printf("\tft_printf = %zu\n\n", i);
}
