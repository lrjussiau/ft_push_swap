/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:42:35 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/14 10:13:17 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **lst, char c, int check)
{
	t_list	*last_node;

	if (!lst || !*lst || !(*lst)-> next)
		return ;
	last_node = *lst;
	while (last_node -> next != NULL)
	{
		last_node = last_node -> next;
	}
	last_node -> next = *lst;
	*lst = (*lst)-> next;
	last_node -> next -> next = NULL;
	if (c == 'a' && check == 0)
		write(1, "ra\n", 3);
	if (c == 'b' && check == 0)
		write(1, "rb\n", 3);
	return ;
}

void	ft_rotates(t_list **a, t_list **b)
{
	ft_rotate(a, 'a', 1);
	ft_rotate(b, 'b', 1);
	write(1, "rr\n", 3);
	return ;
}

void	rotate_both(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap -> target_node && *b != cheap)
		ft_rotates(a, b);
	find_position(a, b);
	is_median(a, b);
}
