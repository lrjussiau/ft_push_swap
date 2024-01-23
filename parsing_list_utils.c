/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:24:22 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/23 12:22:50 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i - 1]) && ft_isdigit(str[i + 1]))
			return (1);
		else if (str[i] == '-' && (str[i + 1] == ' ' || str[i + 1] == '\0'
				|| str[i + 1] == '-'))
			return (1);
		else if (str[i] == ' ' || str[i] == '-')
			i++;
		else if (str[i] < '0' || str[i] > '9')
			return (1);
		else
		{
			nb++;
			i++;
		}
	}
	if (nb == 0)
		return (1);
	return (0);
}

int	check_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 2 && check_int(av[1]) != 0)
		return (write(2, "Error\n", 6));
	if (ac > 2 && check_ac(av, ac) != 0)
		return (write(2, "Error\n", 6));
	while (av[i])
	{
		if (check_int(av[i]) != 0)
			return (write(2, "Error\n", 6));
		i++;
	}
	return (0);
}

int	check_ac(char **av, int ac)
{
	int	n;
	int	i;

	n = 1;
	while (n < ac)
	{
		i = 0;
		while (av[n][i])
		{
			if ((av[n][i] < '0' || av[n][i] > '9') && av[n][i] != '-')
				return (1);
			i++;
		}
		n++;
	}
	return (0);
}

int	check_len(char *str)
{
	long	n;

	n = ft_atol(str);
	if (n > 2147483647 || n < -2147483648)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	check_repeat(t_list **a, char **av, int ac)
{
	t_list	*curent;
	t_list	*lst;
	int		nb;

	curent = *a;
	while (curent != NULL)
	{
		nb = curent -> value;
		lst = curent -> next;
		while (lst != NULL)
		{
			if (nb == lst -> value)
			{
				free_input(*a, av, ac, 0);
				write(2, "Error\n", 6);
				return (1);
			}
			lst = lst -> next;
		}
		curent = curent -> next;
	}
	return (0);
}
