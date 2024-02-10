/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:02:30 by sozdamar          #+#    #+#             */
/*   Updated: 2023/12/15 15:02:32 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_list **head)
{
	if (n_data(*head, 2) > n_data(*head, 1))
	{
		if (n_data(*head, 2) > n_data(*head, 0))
			sa(head);
		else
			ra(head);
	}
	if (n_data(*head, 1) > n_data(*head, 0))
	{	
		if (n_data(*head, 2) > n_data(*head, 0))
		{
			rra(head);
			sa(head);
		}
		else
			rra(head);
	}
	else
	{
		ra(head);
		sa(head);
	}
}

void	worst_sort(t_list **a, t_list **b)
{
	t_list	*min;

	while (*a != NULL)
	{
		min = min_node(a);
		if (node_distance(a, min) < (ft_lstsize(*a) / 2))
		{
			while ((*a)->content != min->content)
				ra(a);
			pb(a,b);
		}
		else
		{
			while ((*a)->content != min->content)
				rra(a);
			pb(a, b);
		}
	}
		while (*b != NULL)
			pa(a, b);
}

void	back_to_b(t_list **a, t_list **b)
{
	t_list	*min;

	while (*b != NULL)
	{
		min = min_node(b);
		if (min->content == (*b)->content)
		{
			pa(a, b);
			ra(a);
		}
		else
			rb(b);
	}
}

void	go_to_a(t_list	**a, t_list **b, int limit, int size)
{
	while (size--) 
	{
		if (limit > (int)(intptr_t)(*a)->content)
			pb(a, b);
		else
			ra(a);
	}
}

void	divide_sort(t_list **a, t_list **b)
{
	int		size;

	go_to_a(a, b, find_it(a, 2), ft_lstsize(*a));
	back_to_b(a, b);
	size = (ft_lstsize(*a) / 2);
	while (size--)
		pb(a, b);
	back_to_b(a, b);
}

//seg fault
void	quarter_divide(t_list **a, t_list **b)
{

	go_to_a(a, b, find_it(a, 1), ft_lstsize(*a));
	back_to_b(a, b);
	go_to_a(a, b, find_it(a, 1), ft_lstsize(*a));
}
