/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:04:31 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/14 13:55:01 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_five(t_list **a, t_list **b)
{
	t_list	*smallest;

	find_position(a, b);
	is_median(a, b);
	while (len_list(a) > 3)
	{
		smallest = find_smallest(a);
		while (*a != smallest)
		{
			if (smallest -> above_median == 1)
				ft_rotate(a, 'a', 0);
			else
				ft_reverse_rotate(a, 'a', 0);
		}
		ft_push(b, a, 'b');
	}
}

void	tiny_sort(t_list **lst, char c)
{
	t_list	*highest_node;
	t_list	*current;

	current = *lst;
	highest_node = find_highest(lst);
	if (*lst == highest_node)
		ft_rotate(lst, c, 0);
	else if ((*lst)-> next == highest_node)
		ft_reverse_rotate(lst, c, 0);
	if ((*lst)-> value > (*lst)-> next -> value)
		ft_swap(lst, c, 0);
}

t_list	*find_highest(t_list **lst)
{
	t_list	*current;
	t_list	*highest;
	int		nb;

	current = *lst;
	nb = current -> value;
	highest = *lst;
	while (current -> next != NULL)
	{
		current = current -> next;
		nb = current -> value;
		if (highest -> value < nb)
			highest = current;
	}
	return (highest);
}
