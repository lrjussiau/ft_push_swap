/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljussiau <ljussiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:26:26 by ljussiau          #+#    #+#             */
/*   Updated: 2023/11/14 13:39:06 by ljussiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <ctype.h>

typedef struct s_list
{
	int				value;
	int				current_position;
	int				target_position;
	int				price;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
}	t_list;

// Split
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
char	**ft_split(char const *s, char c);
// Parsing
t_list	*init_list(t_list *lst, char **av, int ac);
// Parsing Utils
long	ft_atol(const char *str);
int		check_int(char *str);
int		check_input(int ac, char **av);
int		check_len(char *str);
int		check_repeat(t_list **a, char **av, int ac);
int		check_ac(char **av, int ac);
void	free_input(t_list *lst, char **av, int ac, int n);
int		ft_isdigit(int c);
// List utils
t_list	*create_node(int nb);
void	lst_add_back(t_list **begin, int nb);
void	ft_lstdel(t_list **lst, void (*del)(int));
// Functions
void	ft_swap(t_list	**lst, char c, int check);
void	ft_swaps(t_list **lsta, t_list **lstb);
void	ft_push(t_list **dest, t_list **src, char c);
void	ft_rotate(t_list **lst, char c, int check);
void	ft_rotates(t_list **a, t_list **b);
void	ft_reverse_rotate(t_list **lst, char c, int check);
void	ft_reverse_rotates(t_list **a, t_list **b);
// Algo
void	tiny_sort(t_list **lst, char c);
void	process_algo(t_list **a, t_list **b);
void	handle_five(t_list **a, t_list **b);
// Node config
void	configure_node(t_list **a, t_list **b);
void	find_target(t_list **a, t_list **b);
void	find_position(t_list **a, t_list **b);
void	is_median(t_list **a, t_list **b);
void	get_price(t_list **a, t_list **b);
void	get_cheapest(t_list **b);
// Algo mouv
void	make_move(t_list **a, t_list **b);
void	rotate_both(t_list **a, t_list **b, t_list *cheap);
void	reverse_rotate_both(t_list **a, t_list **b, t_list *cheap);
void	finish_rotate(t_list **lst, t_list *cheap, char c);
t_list	*return_cheap(t_list **b);
// Algo utils
int		check_list(t_list **lst);
t_list	*find_highest(t_list **lst);
t_list	*find_smallest(t_list **lst);
int		len_list(t_list **lst);
//Other
void	ft_print_list(t_list *a, t_list *b);

#endif