/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:43:27 by nilamber          #+#    #+#             */
/*   Updated: 2024/05/31 21:10:15 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	i;
	void	*str;

	i = 0;
	if (nitems && SIZE_MAX / nitems < size)
		return (NULL);
	str = malloc(size * nitems);
	if (!str)
		return (NULL);
	while (i < (nitems * size))
		((char *)str)[i++] = '\0';
	return (str);
}
