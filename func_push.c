/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:43:38 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/14 10:13:14 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **dest, t_list **src, char c)
{
	t_list	*node_to_push;

	if (*src == NULL)
		return ;
	node_to_push = *src;
	*src = (*src)-> next;
	if (*dest == NULL)
	{
		*dest = node_to_push;
		node_to_push -> next = NULL;
	}
	else
	{
		node_to_push -> next = *dest;
		*dest = node_to_push;
	}
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
	return ;
}
