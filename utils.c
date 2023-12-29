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
	ft_putendl_fd(msg, 1);
	exit(0);
}

int		is_sorted(t_list **stack)
{
	t_list	*top;

	top = *stack;
	while (top && top->next)
	{
		if (top->data < top->next->data)
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

//find the distance between entered index and the top
int	stack_distance(t_list **stack, int index)
{
	t_list	*top;
	int		distance;

	distance = 0;
	top = *stack;
	while (top->index != index)
	{
		distance++;
		top = top->next;	
	}
	return (distance);
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
		ft_putnbr_fd(temp->data, 1);
		ft_putendl_fd("", 1);
		temp = temp->next;
	}
}

//make the distanced index top
//divide the instructions by two so you get the minimum cmds
void	make_index_top(t_list **stack, int distance)
{
	t_list	*top;
	int		temp;

	if (!distance)
		return ;
	top = *stack;
	temp = ft_lstsize(top) - distance;
	if (distance <= (ft_lstsize(top) / 2))
	{
		while (distance -- > 0)
			ra(stack);
	}
	else
	{
		while (temp-- > 0)
			rra(stack);
	}
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

void	init_stack(t_list **stack, int ac, char **av)
{
	t_list	*node;
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
	while (*args)
	{
		node = ft_lstnew(ft_atoi(*args));
		ft_lstadd_back(stack, node);
		args++;
	}
	if (ac == 2)
		free_str(args);
}