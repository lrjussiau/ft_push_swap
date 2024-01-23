/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:13:28 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/14 10:13:18 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list	**lst, char c, int check)
{
	t_list	*curent;
	t_list	*tmp;
	t_list	*next;

	curent = *lst;
	next = curent -> next;
	if (!curent || !next)
		return ;
	tmp = create_node(curent -> value);
	curent -> value = next -> value;
	next -> value = tmp -> value;
	ft_lstdel(&tmp, (void *)free);
	if (c == 'a' && check == 0)
		write(1, "sa\n", 3);
	if (c == 'b' && check == 0)
		write(1, "sb\n", 3);
	return ;
}

void	ft_swaps(t_list **lsta, t_list **lstb)
{
	ft_swap(lsta, 'a', 1);
	ft_swap(lstb, 'b', 1);
	write(1, "ss\n", 3);
	return ;
}
