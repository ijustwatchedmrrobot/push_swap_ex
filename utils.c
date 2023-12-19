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


//utils
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

void	str_free(char **str)
{
	while (*str)
	{
		free(*str);
		str++;
	}
}

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
		ft_putnbr_fd(temp->value, 1);
		ft_putendl_fd("", 1);
		temp = temp->next;
	}
}


//try to rm index
int	contains(int num, char **av, int i)
{
	i++;
	while (*(argv + i))
	{
		if (ft_atoi(*(argv + i++)) == num)
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

	if (ac == 2)
		args = ft_split(*(av + 1), ' ');
	else
		*(args++) = av;
	while (*args)
	{
		temp = ft_atoi(*args);
		if (!is_str_num(*args))
			ft_error("Error! Not a number.");
		//if (contains)
		if (temp < -2147483648 || temp > 2147483647)
			ft_error("Error! Limit for integer exceeded.");
	
	}
}

// char **args =  {"one", "two", "three", "four", "three"}