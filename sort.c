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

void	divide_sort(t_list **a, t_list **b)
{
	int 	median;
	t_list	*min;
	int		size;

	median = find_median(a);
	size = ft_lstsize(*a);
	while (size--)
	{
		if (median > (int)(intptr_t)(*a)->content)
			pb(a, b);
		else
			ra(a);
	}
	while (*b != NULL)
	{
		min = min_node(b);
		if (min->content == (*b)->content)
		{
			pa(a,b);
			ra(a);
		}
		else
			rb(b);
	}
	size = (ft_lstsize(*a) / 2);
	while (size--)
		pb(a, b);
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