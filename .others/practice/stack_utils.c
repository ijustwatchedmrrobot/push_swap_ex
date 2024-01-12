#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

//stack's 'top' changes with every insert

typedef struct stack_list
{
	int					data;
	struct stack_list	*next;
} Stack;

Stack *last_node(Stack *head)
{
	Stack *temp;

	if (head == NULL)
		return (NULL);
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	push(Stack **top,int data)
{
	Stack	*new;
	Stack	*last;

	new = malloc(sizeof(Stack));
	if (!new)
		return ;
	new->data = data;
	new->next = NULL;
	if (*top == NULL)
		*top = new;
	else
	{
		last = last_node(*top);
		last->next = new;	
	}
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

Stack	**create_stack(int count, ...)
{
	Stack	*top;
	Stack	**root;
	va_list	args;

	top = NULL;
	root = &top;
	va_start(args, count);
	while (count--)
		push(&top, va_arg(args, int));
	va_end(args);
	//printf("%d\n\n", top->index);			//check index of the top if it's always the last index
	return (root);
}

void	print_stack(Stack	**root)
{
	Stack	*temp;

	temp = *root;
	while (temp != NULL)
	{
		printf("data: %d\n", temp->data);
		temp = temp->next;
	}
}

Stack *n_node(Stack *head, int n)
{
	Stack *temp;

	if (head == NULL)
		return (NULL);
	temp = head;
	while (--n)
		temp = temp->next;
	return (temp);
}

void	swap_nodes(Stack **head, int n1, int n2)
{
	Stack	*node1;
	Stack	*node2;
	int	temp;

	node1 = n_node(*head, n1);
	node2 = n_node(*head, n2);
	temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
}


int	main()
{
	Stack	**root;
	
	root = create_stack(5, 1, 2, 3, 4, 5);
	swap_nodes(root, 1, 2);
	print_stack(root);
	return (0);
}



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