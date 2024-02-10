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
		if (top->content > top->next->content)
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

t_list	*n_node(t_list *head, int n)
{
	t_list	*temp;

	if (head == NULL)
		return (NULL);
	temp = head;
	while (--n)
		temp = temp->next;
	return (temp);
}

int	n_data(t_list *head, int n)
{
	t_list	*temp;

	if (head == NULL)
		return (0);
	temp = head;
	while (n--)
		temp = temp->next;
	return ((int)(intptr_t)temp->content);
}

void	swap_nodes(t_list **head, int n1, int n2)
{
	t_list	*node1;
	t_list	*node2;
	void	*temp;
	
	node1 = n_node(*head, n1);
	node2 = n_node(*head, n2);
	temp = node1->content;
	node1->content = node2->content;
	node2->content = temp;
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

t_list	*mid_node(t_list **head)
{
	t_list	*temp;
	int		list_size;

	temp = *head;
	list_size = (ft_lstsize(*head) / 2);
	while (list_size--)
		temp = temp->next;
	return (temp);
}

t_list	*max_node(t_list	**head)
{
	t_list	*temp;
	t_list	*max;

	temp = *head;
	max = temp;
	while (temp->next != NULL)
	{
		if ((int)(intptr_t)temp->content > (int)(intptr_t)max->content)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_list	*min_node(t_list **head)
{
	t_list	*temp;
	t_list	*min;

	temp = *head;
	min = temp;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if ((int)(intptr_t)temp->content < (int)(intptr_t)min->content)
			min = temp;
	}
	return (min);
}

int	node_distance(t_list	**head, t_list *node)
{
	t_list	*temp;
	int		distance;

	temp = *head;
	distance = 0;
	while (temp != NULL &&temp->content != node->content)
	{
		distance++;
		temp = temp->next;
	}
	return (distance);
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*init_array(t_list **head)
{
	int	*arr;
	int	size;
	int	i;
	t_list	*temp;

	i = 0;
	size = ft_lstsize(*head);
	temp = *head;
	arr = malloc(sizeof(int) * size);
	while (size > i)
	{
		arr[i] = (int)(intptr_t)temp->content;
		temp = temp->next;
		i++;
	}

	return (arr);
}

//int find equals to whichever quarter (1st, 2nd or 3rd)
int	find_it(t_list	**a, int find)
{
	int *arr;
	int	size;

	size = ft_lstsize(*a);
	arr = init_array(a);
	sort_arr(arr, size);
	if (find == 1)
		return (arr[size / 4]);
	else if (find == 2)
		return (arr[size / 2]);
	else if (find == 3)
		return (arr[(size * 3) / 4]);
	else
		return (-1);
}

//function which pushes to b in minimum set of instructions
void	go_to_b(t_list **a, t_list **b, t_list *node)
{
	t_list	*head;
	int dist;

	head = *a;
	dist = node_distance(a, node);
	if (head->content == node->content)
		pb(a, b)
	if (dist < ft_lstsize(*a))
	{
		while (node->content != head->next->content)
			ra(a);
		sa(a);
		pb(a, b);
	}
	else
	{
		while (node->content != head->content)
			rra(a);
		pb(a, b);
	}
}
