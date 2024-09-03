/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:24:14 by nilamber          #+#    #+#             */
/*   Updated: 2024/09/03 16:32:38 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse(int c, char **v)
{
	int		i;
	int		j;

	i = 1;
	while (i < c)
	{
		j = 0;
		while (v[i][j])
		{
			if ((v[i][j] < '0' || v[i][j] > '9')
				&& ((v[i][j] != 32 && (v[i][j] < 9 || v[i][j] > 13))
					&& ((v[i][j] != '-') || (v[i][j] == '-'
						&& (((v[i][j + 1]) > '9' || (v[i][j + 1])
							< '0') || (j != 0 && ((v[i][j - 1]) != 32
								|| (v[i][j - 1] < 9 || (v[i][j - 1])
									> 13))))))))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int count(int c, char **v)
{
	int		i;
	int		j;
	int		res;

	i = 1;
	res = 0;
	while (i < c)
	{
		j = 0;
		while (v[i][j])
		{
			if (v[i][j] >= '0' && v[i][j] <= '9')
				res++;
			while (v[i][j] >= '0' && v[i][j] <= '9')
				j++;
			j += (v[i][j] != 0);
			printf("res = %d\n", res);
		}
		i++;
	}
	printf("res = %d\n", res);
	return (res);
}

int	fatoi (char *str, int status)
{
	int	res;
	int	sign;
	int	in;

	in = 0;
	res = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		if (in > 10 || ((in == 9 && res > 24748364) || (in == 10
				&& ((sign > 0 && *str > '7') || (sign < 0 && *str > '8')))))
		{
			status = 1;
			return (res);
		}
		res += (*str - '0');
		res *= 10;
		in++;
		str++;
	}
	res *= sign;
	return (res);
}

int	*stock(char **v, int count, int c, int status)
{
	int	i;
	int	k[2];
	int	*list;
	int res;
	
	list = malloc(sizeof(int) * count);
	i = 1;
	*k = 0;
	while (i < c)
	{
		k[1] = 0;
		res = fatoi(v[i], status);
		while (k[1] < *k)
		{
			if (res == list[k[1]++] || status)
			{
				status = 1;
				return (list);
			}
		}
		list[k[0]++] = res;
		while (*v[i] && (*v[i] != '-' || (*v[i] < '0' || *v[i] > '9')))
			v[i]++;
		if (!*v[i])
			i++;
	}
	return (list);
}

int	main(int c, char **v)
{
	int	*lst;
	int status;
	int	i = -1;

	status = 0;
	if (c == 1)
		return (0);
	if (c < 2)
		return (write(1, "Error1\n", 7));
	if (parse(c, v))
		return (write(1, "Error2\n", 7));
	lst = stock(v, count(c, v), c, status);
	if (status == 1)
	{
		free(lst);
		return (write(1, "Error3\n", 7));
	}
	printf("%d\n", count(c, v));
	while (i++ < count(c, v))
		printf("lst[%d] = %d\n", i, lst[i]);
	free(lst);
}
