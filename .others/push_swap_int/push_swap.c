/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:02:30 by sozdamar          #+#    #+#             */
/*   Updated: 2023/12/15 15:02:32 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdarg.h>

void	push_ft(t_list **top, int content)
{
	t_list	*temp;

	temp = ft_lstnew(content);
	ft_lstadd_back(top, temp);
}

int	main(int ac, char **av)
{
	t_list	**head;

	head = (t_list **)malloc(sizeof(t_list **));
	*head = NULL;
	printf("test\n");
	if (ac < 1)
	{
		printf("if didn't worked :( %s\n", av[1]);
		return (0);
	}
	else
	{
		init_stack(head, ac, av);
		print_stack(*head);
	}
}