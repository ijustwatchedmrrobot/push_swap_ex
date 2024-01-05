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

//commands
void	swap(t_list **stack);
void	sa(t_list	**stack_a);
void	sb(t_list	**stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_dst, t_list **stack_src);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	rotate(t_list	**stack);
void	ra(t_list	**stack_a);
void	rb(t_list	**stack_b);
void	rr(t_list	**stack_a, t_list	**stack_b);
void	reverse_rotate(t_list	**stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

# endif