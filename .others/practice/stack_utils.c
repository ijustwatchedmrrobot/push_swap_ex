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

void	push(Stack **top,int data)
{
	Stack	*temp;

	temp = malloc(sizeof(Stack));
	temp->next = *top;
	temp->data = data;
	if (*top == NULL)
		temp->index = -1;
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


int	main()
{
	Stack	**root;
	
	root = create_stack(5, 2, 1, 8, 6, 15);
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