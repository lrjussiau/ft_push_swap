/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_algo_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:53:28 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/14 13:50:13 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_move(t_list **a, t_list **b)
{
	t_list	*cheap;

	cheap = return_cheap(b);
	if (cheap->above_median == 1 && cheap->target_node->above_median == 1)
		rotate_both(a, b, cheap);
	if (cheap->above_median == 0 && cheap->target_node->above_median == 0)
		reverse_rotate_both(a, b, cheap);
	finish_rotate(a, cheap, 'a');
	finish_rotate(b, cheap, 'b');
	ft_push(a, b, 'a');
}

t_list	*return_cheap(t_list **b)
{
	t_list	*current;

	current = *b;
	while (current != NULL)
	{
		if (current -> cheapest == 1)
			return (current);
		current = current -> next;
	}
	return (NULL);
}

void	finish_rotate(t_list **lst, t_list *cheap, char c)
{
	t_list	*current;

	current = *lst;
	if (c == 'a')
	{
		while (*lst != cheap -> target_node)
		{
			if (cheap -> target_node -> above_median == 1)
				ft_rotate(lst, c, 0);
			else
				ft_reverse_rotate(lst, c, 0);
		}
	}
	else
	{
		while (*lst != cheap)
		{
			if (cheap -> above_median == 1)
				ft_rotate(lst, c, 0);
			else
				ft_reverse_rotate(lst, c, 0);
		}
	}
}
