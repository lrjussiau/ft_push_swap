/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_config_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:07:29 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/14 10:13:27 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target(t_list **a, t_list **b)
{
	t_list	*current_b;
	t_list	*current_a;
	long	n;

	current_b = *b;
	current_a = *a;
	while (current_b != NULL)
	{
		n = LONG_MAX;
		while (current_a != NULL)
		{
			if (current_b->value < current_a->value && current_a -> value < n)
			{
				n = current_a->value;
				current_b->target_node = current_a;
			}
			current_a = current_a->next;
		}
		current_a = *a;
		if (n == LONG_MAX)
			current_b->target_node = find_smallest (a);
		current_b = current_b->next;
	}
}

void	find_position(t_list **a, t_list**b)
{
	t_list	*current_b;
	t_list	*current_a;
	int		nb;

	current_b = *b;
	current_a = *a;
	nb = 0;
	while (current_a != NULL)
	{
		current_a -> current_position = nb;
		nb++;
		current_a = current_a -> next;
	}
	nb = 0;
	while (current_b != NULL)
	{
		current_b -> current_position = nb;
		current_b->target_position = current_b->target_node->current_position;
		nb++;
		current_b = current_b -> next;
	}
}

void	is_median(t_list **a, t_list **b)
{
	t_list	*current_b;
	t_list	*current_a;
	int		nb;

	current_b = *b;
	current_a = *a;
	nb = len_list(a);
	while (current_a != NULL)
	{
		if (current_a -> current_position < nb / 2)
			current_a -> above_median = true;
		else
			current_a -> above_median = false;
		current_a = current_a -> next;
	}
	nb = len_list(b);
	while (current_b != NULL)
	{
		if (current_b -> current_position < nb / 2)
			current_b -> above_median = true;
		else
			current_b -> above_median = false;
		current_b = current_b -> next;
	}
}

void	get_price(t_list **a, t_list **b)
{
	t_list	*current;
	int		len_a;
	int		len_b;

	current = *b;
	len_a = len_list(a);
	len_b = len_list(b);
	while (current != NULL)
	{
		current -> price = current -> current_position;
		if (current -> above_median == 0)
			current -> price = len_b - current -> current_position;
		if (current -> target_node -> above_median == 1)
			current -> price += current -> target_position;
		else
			current -> price += len_a - current -> target_position;
		current = current -> next;
	}
}

void	get_cheapest(t_list **b)
{
	t_list	*current;
	int		n;

	current = *b;
	n = current -> price;
	while (current != NULL)
	{
		if (n > current -> price)
			n = current -> price;
		current = current -> next;
	}
	current = *b;
	while (current != NULL)
	{
		if (current -> price == n)
			current -> cheapest = true;
		else
			current -> cheapest = false;
		current = current ->next;
	}
}
