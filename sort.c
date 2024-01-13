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

void	quick_sort(t_list **a, t_list **b)
{
	int		temp;
	int		pivot;

	temp = *a;
	pb(a, b);
	pivot = (int)(intptr_t)(*b->content);
	while (temp->next != NULL)
	{
		if (pivot > temp->content)
			pb(a, b);
		temp = temp->next;
	}
}