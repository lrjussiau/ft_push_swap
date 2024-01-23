/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:43:37 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/14 10:13:23 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int nb)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node -> value = nb;
	new_node -> next = NULL;
	return (new_node);
}

void	lst_add_back(t_list **begin, int nb)
{
	t_list	*current;
	t_list	*new_node;

	new_node = create_node(nb);
	if (*begin == NULL)
	{
		*begin = new_node;
		return ;
	}
	current = *begin;
	while (current -> next != NULL)
		current = current -> next;
	current -> next = new_node;
	return ;
}

void	ft_lstdel(t_list **lst, void (*del)(int))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	if (!del || !lst || !*lst)
		return ;
	while (current != NULL)
	{
		next = current -> next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

int	len_list(t_list **lst)
{
	t_list	*current;
	int		nb;

	nb = 0;
	current = *lst;
	while (current != NULL)
	{
		current = current -> next;
		nb += 1;
	}
	return (nb);
}
