/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:32:24 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/23 12:34:21 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_print_list(t_list *a, t_list *b)
{
	int	nba;
	int	nbb;

	while (a != NULL || b != NULL)
	{
		nba = (a != NULL) ? a->value : 0;
		nbb = (b != NULL) ? b->value : 0;

		if (a != NULL && b != NULL)
		{
			printf("%d %d\n", nba, nbb);
			a = a->next;
			b = b->next;
		}
		else if (a != NULL)
		{
			printf("%d\n", nba);
			a = a->next;
		}
		else if (b != NULL)
		{
			printf("  %d\n", nbb);
			b = b->next;
		}
	}
	printf("_ _\n");
	printf("a b\n");
}
*/
int	check_list(t_list **lst)
{
	t_list	*current;
	int		nb;

	current = *lst;
	while (current -> next != NULL)
	{
		nb = current -> value;
		current = current -> next;
		if (nb > current -> value)
		{
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	a = init_list(a, av, ac);
	if (a == 0)
	{
		return (0);
	}
	if (check_list(&a))
	{
		if (len_list(&a) <= 3)
			tiny_sort(&a, 'a');
		else
			process_algo(&a, &b);
	}
	ft_lstdel(&a, (void *)free);
	ft_lstdel(&b, (void *)free);
	return (0);
}
/*
int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	a = init_list(a, av, ac);
	if (a == 0)
	{
		return (0);
	}
	ft_print_list(a, b);
	printf("\n-------\n");
	if (check_list(&a))
	{
		if (len_list(&a) <= 3)
			tiny_sort(&a, 'a');
		else
			process_algo(&a, &b);
	}
	printf("\n-------\n");
	ft_print_list(a, b);

	while (b != NULL)
	{
		printf("Node : %d\n", b->value);
		printf("Target: %d\n", b->target_node->value);
		printf("Current position : %d\n", b->current_position);
		printf("Target position : %d\n", b->target_position);
		printf("Above median : %d\n", b->above_median);
		printf("Price : %d\n", b->price);
		printf("Cheap : %d\n", b->cheapest);
		printf("________________\n");
		b = b -> next;
	}
	return (0);
}
*/
