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
#include <stdarg.h>

void	push_ft(t_list **top, int content)
{
	t_list	*temp;

	temp = ft_lstnew((void *)(intptr_t)content);
	ft_lstadd_back(top, temp);
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
		push_ft(&top, va_arg(args, int));
	va_end(args);
	return (root);
}

int	main(int ac, char **av)
{
	t_list	**head = NULL;
	ft_printf("test\n");
	if (ac < 2)
	{
		ft_printf("if didn't worked :( %s\n", av[1]);
		return (0);
	}
	else
	{
		//head = create_stack(3, 1, 2, 3);
		init_stack(head, ac, av);
		print_stack(*head);
	}
}