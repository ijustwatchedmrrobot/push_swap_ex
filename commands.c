/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:02:30 by sozdamar          #+#    #+#             */
/*   Updated: 2023/12/15 15:02:32 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap first two elements
void	swap(t_list **stack)
{
	t_list	*top;
	t_list	*next;
	t_list	*temp;

	//*stack -> &stack ??
	if (ft_lstsize(*stack) < 2)
		return (-1);
	top = *stack;
	next = top->next;
	if (!top && !next)
		ft_error("Swapping error!");
	temp = top;
	top = next;
	next = temp;
}

// swaps a
void	sa(t_list	**stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_printf("sa");
}

// swaps b
void	sb(t_list	**stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_printf("sb");
}

// swaps both a&b
void	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss");
}

//pushes top (head) of source to dest
void	push(t_list **stack_dst, t_list **stack_src)
{
	t_list	*temp;
	t_list	*top_dst;
	t_list	*top_src;

	if (ft_lstsize(*stack_src) == 0)
		return (-1);
	top_dst = *stack_dst;
	top_src = *stack_src;
	temp = top_src;
	top_src = top_src->next;
	*stack_src = top_src;
	if (!top_dst)
	{
		top_dst = temp;
		top_dst->next = NULL;
		*stack_dst = top_dst;
	}
	else
	{
		temp->next = top_dst;
		*stack_dst = temp;
	}
}

//pushes b_top to a
void	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_printf("pa");
}

//pushes a_top to b
void	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_printf("pb");	
}

//shift all the elements of stack by one, first element becomes the last
// NULL <- 1 <- 2 <- 3 <- 4 <- 5 <- *stack
// NULL <- 1 <- 2 <- 3 <- 4 <- 5 <- 1 <- ...
// NULL <- 1 <- 2 <- 3 <- 4 <- *stack <- 5 <- 1 <- ...
// NULL <- 5 <- 1 <- 2 <- 3 <- 4 <- *stack
//change the 'next' of last two elements (top and prev)
void	rotate(t_list	**stack)
{
	t_list	*top;
	t_list	*bot;
	
	if (ft_lstsize(*stack) < 2)
		return (-1);
	top = *stack;
	bot = ft_lstlast(*stack);
	*stack = top->next;
	top->next = NULL;
	bot->next = top;
}

void	ra(t_list	**stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_printf("ra");
}

void	rb(t_list	**stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_printf("rb");
}

void	rr(t_list	**stack_a, t_list	**stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr");
}

//Shift all the elements of the stack by one in the reverse direction
// NULL <- 1 <- 2 <- 3 <- 4 <- 5 <- *stack last becomes top
// NULL <- NULL <- 2 <- 3 <- 4 <- 5 <- *stack
// NULL <- 2 <- 3 <- 4 <- 5 <- 1 <- *stack
void	reverse_rotate(t_list	**stack)
{
	t_list	*top;
	t_list	*bot;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	top = *stack;
	bot = ft_lstlast(*stack);
	while (top)
	{
		if (top->next->next == NULL)
		{
			top->next = NULL;
			break;
		}
		top = top->next;
	}
	bot->next = *stack;
	*stack = bot;
}

void	rra(t_list **stack_a)
{	
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_printf("rra");
}

void	rrb(t_list **stack_b)
{	
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_printf("rrb");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	ft_printf("rrr");
}