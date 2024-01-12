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

void	sort3(t_list **h)
{
	if (n_data(*h, 2) > n_data(*h, 1))
	{
		if (n_data(*h, 2) > n_data(*h, 0))
			sa(h);
		else
			ra(h);
	}
	else
	{	
		if (n_data(*h, 2) > n_data(*h, 0))
			ra(h);
		else if (n_data(*h, 1) > n_data(*h, 0))
			ra(h);
		else
		{
			rra(h);
			sa(h);
		}
	}
}