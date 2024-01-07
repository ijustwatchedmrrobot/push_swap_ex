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

//UTILS
void	ft_error(char *msg)
{
	ft_printf("%s", msg);
	exit(0);
}

int		is_sorted(t_list **stack)
{
	t_list	*top;

	top = *stack;
	while (top && top->next)
	{
		if (top->content < top->next->content)
			return (0);
		top = top->next;
	}
	return (1);
}


//free from last (check!!)
void	free_str(char **str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	while (i >= 0)
		free(*(str + i--));
}

void	free_stack(t_list **stack)
{
	t_list	*top;
	t_list	*temp;

	top = *stack;
	while (top)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
	free(stack);
}

void	print_stack(t_list *top)
{
	t_list	*temp;

	temp = top;
	while (temp != NULL)
	{
		ft_printf("%d\n",(int)(intptr_t)temp->content);
		temp = temp->next;
	}
}

//errors!!
void	print_stacks(t_list *a, t_list *b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = a;
	temp_b = b;
	while (temp_a != NULL || temp_b != NULL)
	{
		ft_printf("%d   %d\n",(int)(intptr_t)temp_a->content, (int)(intptr_t)temp_b->content);
		temp_a = temp_a->next;
		temp_b = temp_b->next;
	}
	ft_printf("_   _\na   b\n");
}

//ARGS
//try to rm index
int	contains(int num, char **av, int i)
{
	i++;
	while (*(av + i))
	{
		if (ft_atoi(*(av + i++)) == num)
			return (1);
	}
	return (0);
}

int	is_str_num(char *num)
{
	if (*num == '-')
		num++;
	while (*num)
	{
		if (!ft_isdigit(*num++))
			return (0);
	}
	return (1);
}

void	check_args(int ac, char **av)
{
	long	temp;
	char	**args;
	int		i;

	i = 0;
	if (ac == 2)
		args = ft_split(*(av + 1), ' ');
	else
	{
		i++;
		args = av;
	}
	while (*(args + i))
	{
		temp = ft_atoi(*(args + i));
		if (!is_str_num(*(args + i)))
			ft_error("Error! Not a number.");
		if (contains(temp, args, i))
			ft_error("Error, reiteration occurs.");
		if (temp < -2147483648 || temp > 2147483647)
			ft_error("Error! Limit for integer exceeded.");
		i++;
	}
	if (ac == 2)
		free_str(args);
}

void	push_ft(t_list **top, int content)
{
	t_list	*temp;

	temp = ft_lstnew((void *)(intptr_t)content);
	ft_lstadd_back(top, temp);
}

void	init_stack(t_list **stack, int ac, char **av)
{
	char	**args;
	int		i;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		push_ft(stack, ft_atoi(args[i]));
		i++;
	}
	if (ac == 2)
		free_str(args);
}