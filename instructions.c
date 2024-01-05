/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:02:30 by sozdamar          #+#    #+#             */
/*   Updated: 2023/12/15 15:02:32 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	t_list	*temp;

	if (ft_lstsize(*stack) < 2)
		ft_error("stack less than 2");
	top = *stack;
	next = top->next;
	if (!top && next!)
		ft_error("swap error");
	temp = top;
	top = next;
	next = temp;
}

void	sa(t_list **stack)
{
	swap(stack);
	ft_printf("sa");
}

void	sb(t_list **stack)
{
	swap(stack);
	ft_printf("sb");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss");
}

void	push(t_list	**dst, t_list **src)
{
	t_list	*temp;
	t_list	*top_dst;
	t_list	*top_src;

	if (ft_lstsize(*src) == 0)
		ft_error("source stack is empty");
	top_dst = *dst;
	top_src = *src;
	temp = top_src;
	*src = top_src->next;
	if (!top_dst)
	{
		top_dst = temp;
		top_dst->next = NULL;
		*dst = top_dst;
	}
	else
	{
		temp->next = top_dst;
		*dst = temp;
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb");
}

void	rotate()
{
	
}