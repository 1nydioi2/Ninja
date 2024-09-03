/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 08:37:30 by nilamber          #+#    #+#             */
/*   Updated: 2024/08/12 15:51:54 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>

typedef struct s_list
{
	int				content;
	int				number;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;
t_list	*ft_lstnew(int content, int number);
t_list	*ft_lstadd_front(char **lst, t_list *new);
#endif
