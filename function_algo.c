/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:29:30 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/14 13:44:08 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_algo(t_list **a, t_list **b)
{
	t_list	*smallest;

	if (len_list(a) == 5)
		handle_five(a, b);
	while (len_list(a) > 3)
	{
		ft_push(b, a, 'b');
	}
	tiny_sort(a, 'a');
	while (*b != NULL)
	{
		configure_node(a, b);
		make_move(a, b);
	}
	find_position(a, b);
	smallest = find_smallest(a);
	if (smallest -> above_median == 1)
		while (*a != smallest)
			ft_rotate(a, 'a', 0);
	else
		while (*a != smallest)
			ft_reverse_rotate(a, 'a', 0);
}

t_list	*find_smallest(t_list **lst)
{
	t_list	*current;
	t_list	*smallest;
	int		nb;

	current = *lst;
	nb = current -> value;
	smallest = *lst;
	while (current != NULL)
	{
		nb = current -> value;
		if (smallest -> value > nb)
			smallest = current;
		current = current -> next;
	}
	return (smallest);
}
