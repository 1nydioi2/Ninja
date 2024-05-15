/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:54:22 by nilamber          #+#    #+#             */
/*   Updated: 2024/05/15 21:21:58 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 24
#endif
#include "get_next_line.h"

char	**ft_onen_split(char *buffer, size_t read_size)
{
	size_t		i;
	char	**array;

	array = malloc(sizeof(char *) * 2);
	array[0] = malloc(sizeof(char) * (read_size + 1));
	array[1] = malloc(sizeof(char) * (read_size + 1));

	i = 0;
	while (i < read_size)
	{
		if (buffer[i] == '\n')
		{
			array[1] = ft_strdup(&buffer[i + 1]);
			array[0] = ft_strdup(ft_substr(buffer, 0, i + 1));
			return (array);
		}
		i++;
	}
	*array = ft_strdup(buffer);
	return (array);
}

char	*get_next_line(int fd)
{
	char			*raisin;
	static char	*pepin = NULL;
	char	eau[BUFFER_SIZE + 1];
	size_t			i;
	char		**array;

	eau[BUFFER_SIZE] = 0;
	if (pepin && ft_onen_split(pepin, (ft_strlen(pepin) + 1))[1])
	{
		printf("caca\n");
		raisin = ft_strdup(ft_onen_split(pepin, (ft_strlen(pepin) + 1))[0]);
		pepin = ft_strdup(ft_onen_split(pepin, (ft_strlen(pepin) + 1))[1]);
		return (raisin);
	}
	else
	{
		i = read(fd, eau, BUFFER_SIZE);
		array = ft_onen_split(eau, BUFFER_SIZE);
		printf("eau = %s\n", eau);
	/*printf ("array[0] = \"%s\"\n", array[0]);
	printf ("array[1] = \"%s\"\n", array[1]);
	printf ("pepin = \"%s\"\n", pepin);*/
		raisin = ft_strjoin(pepin, array[0]);
	//printf("raisin = \"%s\"\n", raisin);
		while (!array[1] && i > 0)
		{
		//printf("ib = %zu\n", i);
			ft_bzero(eau, BUFFER_SIZE);
			i = read(fd, eau, BUFFER_SIZE);
			if (array[0])
				free (array[0]);
			array = ft_onen_split(eau, i);
			raisin = ft_strjoin(raisin, array[0]);
		}
		pepin = ft_strdup(array[1]);
	/*printf ("array[0] = \"%s\"\n", array[0]);
	printf ("array[1] = \"%s\"\n", array[1]);
	printf ("pepin = \"%s\"\n", pepin);*/
		if (array[0])
			free (array[0]);
		if (array[1])
			free (array[1]);
		free (array);
		if (i < 1)
			return (NULL);
		return (raisin);
	}
}
