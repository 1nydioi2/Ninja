/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:39:35 by nilamber          #+#    #+#             */
/*   Updated: 2024/05/30 17:58:12 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	i;
	int	hex;

	hex = -9;
	i = ft_printf("ft_printf = %x", hex);
	ft_printf("\tft_printf = %d\n\n", i);
	i = printf("printf = %x\t", hex);
	printf("printf = %d\n", i);
}
