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
int	swap(t_list **stack)
{
	t_list	*top;
	t_list	*next;
	t_list	*temp;

	//*stack -> &stack ??
	if (ft_lstsize(&stack) < 2)
		return (-1);
	top = *stack;
	next = top->next;
	if (!top && !next)
		ft_error("Swapping error!");
	temp = top;
	top = next;
	next = temp;
	return (0);
}

// swaps a
int	sa(t_list	**stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

// swaps b
int	sb(t_list	**stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

// swaps both a&b
int	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(stack_a) < 2 || ft_lstsize(stack_b))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
