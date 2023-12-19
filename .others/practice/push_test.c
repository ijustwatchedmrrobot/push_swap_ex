#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

//stack's 'top' changes with every insert

typedef struct stack_list
{
	int					data;
	int					index;
	struct stack_list	*next;
} Stack;

Stack	*ft_lstlast(Stack *lst)
{
	Stack	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while ((temp->next) != NULL)
		temp = temp->next;
	return (temp);
}


int	ft_lstsize(Stack *lst)
{
	int		size;
	Stack	*temp;

	size = 0;
	temp = lst;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}


void	push(Stack **top,int data)
{
	Stack	*temp;

	temp = malloc(sizeof(Stack));
	temp->next = *top;
	temp->data = data;
	if (*top == NULL)
		temp->index = 0;
	else
		temp->index = (*top)->index + 1;
	*top = temp;
}

// a -> b -> c -> d -> top

void	pop(Stack **top)
{
	Stack	*temp;

	temp = malloc(sizeof(Stack));
	temp = *top;
	*top = temp->next;
	free(temp);
}

Stack	*create_stack(int count, ...)
{
	Stack	*top;
	Stack	**root;
	va_list	args;

	top = NULL;
	root = &top;
	va_start(args, count);
	while (count--)
		push(&top, va_arg(args, int));

	//printf("\n%d, %d, %d\n", top->data, top->next->data );	//check if the top and the direction is true
	//printf("%d\n\n", top->index);								//check index of the top if it's always the last index
	return (*root);
}

void	print_stack(Stack	**root)
{
	Stack	*temp;

	temp = *root;
	while (temp != NULL)
	{
		printf("data: %d\n", temp->data);
		printf("index: %d\n", temp->index);
		temp = temp->next;
	}
}

int	ft_push(Stack **stack_dst, Stack **stack_src)
{
	Stack	*temp;
	Stack	*top_dst;
	Stack	*top_src;

	if (ft_lstsize(*stack_src) == 0)
		return (-1);

	top_dst = *stack_dst;
	top_src = *stack_src;

	temp = *stack_src; 			//keep the top of the source stack in temp
	top_src = top_src->next;	//assign prev. index to top of b (..., 5, 6(top_src)) --> (..., 5(top_src), 6)
	*stack_src = top_src;		//assign top of temp b to the top of stack b

	if (!top_dst)				//if stack a is null, assign temp (keeps source of top b) top the top of stack a
	{
		top_dst = temp;
		top_dst->next = NULL;
		*stack_dst = top_dst;
	}
	else
	{							//if stack a is not null, set the temp (source of top b), as the top of a which keeps the address of the current top
		temp->next = top_dst;	//and assign it to the top of a
		*stack_dst = temp;
	}
	return (0);
}

int	rotate(Stack	**stack)
{
	Stack	*top;
	Stack	*bot;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	top = *stack;
	bot = ft_lstlast(*stack);
	*stack = top->next;
	top->next = NULL;
	bot->next = top;
	return (0);
}

int main()
{
	Stack	*root;
	root = create_stack(5, 1, 2, 3, 4, 5);
	printf("before rotate:\n");
	print_stack(&root);
	rotate(&root);
	printf("after rotate:\n");
	print_stack(&root);
}

/*
int	main()
{
	Stack	*root_a;
	Stack	*root_b;
	
	root_a = create_stack(6, 10, 20, 30, 40, 50, 60);
	root_b = create_stack(6, 1, 2, 3, 4, 5, 6);
	
	printf("a first\n");
	print_stack(&root_a);
	printf("\n");
	
	printf("b first\n");
	print_stack(&root_b);
	printf("\n");
	
	ft_push(&root_a, &root_b);
	
	printf("a last\n");
	print_stack(&root_a);
	printf("\n");
	
	printf("b last\n");
	print_stack(&root_b);

	return (0);
}
*/
	
/*
int main()
{
	Stack	*top;
	Stack	**root;

	top = NULL;
	root = &top;
	push(&top, 5);
	push(&top, 80);
	pop(&top);
	push(&top, 10);
	print_stack(*root);
}
*/