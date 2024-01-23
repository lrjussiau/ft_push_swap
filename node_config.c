/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:06:42 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/14 10:13:28 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	configure_node(t_list **a, t_list **b)
{
	find_target(a, b);
	find_position(a, b);
	is_median(a, b);
	get_price(a, b);
	get_cheapest(b);
}
