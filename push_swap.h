/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:02:30 by sozdamar          #+#    #+#             */
/*   Updated: 2023/12/15 15:02:32 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
#include "ft_printf/ft_printf.h"

//utils
void	ft_error(char *msg);
int		is_sorted(t_list **stack);
void	free_str(char **str);
int		stack_distance(t_list **stack, int index);
void	free_stack(t_list **stack);
void	print_stack(t_list *top);
void	make_index_top(t_list **stack, int distance);
int		contains(int num, char **av, int i);
int		is_str_num(char *num);
void	check_args(int ac, char **av);
void	push_ft(t_list **top, int content);
void	init_stack(t_list **stack, int ac, char **av);
t_list	*n_node(t_list *head, int n);
int		n_data(t_list *head, int n);
void	swap_nodes(t_list **head, int n1, int n2);
t_list	*mid_node(t_list **head);
t_list	*max_node(t_list	**head);
t_list	*min_node(t_list **head);
int		node_distance(t_list	**head, t_list *node);
int		find_median(t_list **head);
void	sort_arr(int *arr, int size);
int		find_quarter1(t_list **head);
int		find_quarter2(t_list **head);

//commands
int	swap(t_list **stack);
int	sa(t_list	**stack_a);
int	sb(t_list	**stack_b);
int	ss(t_list **stack_a, t_list **stack_b);
int	push(t_list **stack_dst, t_list **stack_src);
int	pa(t_list **stack_a, t_list **stack_b);
int	pb(t_list **stack_a, t_list **stack_b);
int	rotate(t_list	**stack);
int	ra(t_list	**stack_a);
int	rb(t_list	**stack_b);
int	rr(t_list	**stack_a, t_list	**stack_b);
int	reverse_rotate(t_list	**stack);
int	rra(t_list **stack_a);
int	rrb(t_list **stack_b);
int	rrr(t_list **stack_a, t_list **stack_b);

//sort
void	sort3(t_list **h);
void	quick_sort(t_list **a, t_list **b);
void	worst_sort(t_list **a, t_list **b);
void	divide_sort(t_list **a, t_list **b);
void	back_to_b(t_list **a, t_list **b);
void	go_to_a(t_list	**a, t_list **b, int limit);
void	quarter_divide(t_list **a, t_list **b);

//error
void	print_stacks(t_list *a, t_list *b);

# endif