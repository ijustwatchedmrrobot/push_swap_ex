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

void	pusht(t_list **top,int content)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	temp->next = *top;
	temp->content = content;
	*top = temp;	
}

t_list	**create_stack(int count, ...)
{
	t_list	*top;
	t_list	**root;
	va_list	args;

	top = NULL;
	root = &top;
	va_start(args, count);
	while (count--)
		pusht(&top, va_arg(args, int));
	va_end(args);
	return (root);
}

void	print_stacks(t_list	**root)
{
	t_list	*temp;

	temp = *root;
	while (temp != NULL)
	{
		printf("data: %d\n",temp->content);
		temp = temp->next;
	}
}

int	main(int ac, char **av)
{
	t_list	**head = NULL;
	printf("test\n");
	if (ac < 1)
	{
		printf("if didn't worked :( %s\n", av[1]);
		return (0);
	}
	else
	{
		//head = create_stack(3, 1, 2, 3);
		init_stack(head, ac, av);
		print_stack(*head);
	}
}