/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:59:57 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/23 12:25:12 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_input(t_list *lst, char **av, int ac, int n)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[i])
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
	if (lst != NULL && n == 0)
	{
		ft_lstdel(&lst, (void *)free);
	}
}

t_list	*init_list(t_list *lst, char **av, int ac)
{
	int		i;

	i = 1;
	if (check_input(ac, av) != 0)
		return (0);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = 0;
	}
	while (av[i] != NULL)
	{
		if (check_len(av[i]) != 0)
		{
			free_input(lst, av, ac, 0);
			return (0);
		}
		lst_add_back(&lst, (int)ft_atol(av[i]));
		i++;
	}
	if (check_repeat(&lst, av, ac) != 0)
		return (0);
	free_input(lst, av, ac, 1);
	return (lst);
}
