/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:45:08 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/14 10:13:15 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **lst, char c, int check)
{
	t_list	*last_node;
	t_list	*new_head;
	t_list	*new_last;

	if (!lst || !*lst || !(*lst)-> next)
		return ;
	last_node = *lst;
	while (last_node -> next != NULL)
	{
		new_last = last_node;
		last_node = last_node -> next;
	}
	new_head = last_node;
	new_last -> next = NULL;
	new_head -> next = *lst;
	*lst = new_head;
	if (c == 'a' && check == 0)
		write(1, "rra\n", 4);
	if (c == 'b' && check == 0)
		write(1, "rrb\n", 4);
	return ;
}

void	ft_reverse_rotates(t_list **a, t_list **b)
{
	ft_reverse_rotate(a, 'a', 1);
	ft_reverse_rotate(b, 'b', 1);
	write(1, "rrr\n", 4);
	return ;
}

void	reverse_rotate_both(t_list **a, t_list **b, t_list *cheap)
{
	while (*a != cheap -> target_node && *b != cheap)
		ft_reverse_rotates(a, b);
	find_position(a, b);
	is_median(a, b);
}
