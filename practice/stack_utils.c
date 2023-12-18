#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

//stack's 'top' is the root of the linked list and changes with every insert

typedef struct stack_list
{
	int					data;
	int					index;
	struct stack_list	*next;
} Stack;

void	push(Stack **top, int data)
{
	Stack	*temp;
	Stack	*ptr;
	static int index = -1;

	temp = malloc(sizeof(Stack));
	temp->next = NULL;
	temp->data = data;
	temp->index = index;
	if (*top == NULL)
		*top = temp;	
	else
	{
		ptr = malloc(sizeof(Stack));
		ptr->next = *top;
		ptr->data = data;
		*top = ptr;
	}
}

//temp2->temp1->top
//temp1->top
//top
void	create_stack(Stack **top,int nums, ...)
{
	va_list	args;
	int	counter = nums;

	va_start(args, nums);
	while ((counter--) != 0)
		push(&top, va_arg(args, int));
	va_end(args);
}

void	print_stack(Stack **top)
{
	Stack	*temp;

	temp = malloc(sizeof(Stack));
	temp = *top;
	while ((temp->next) != NULL)
	{
		printf("data: %d\n", temp->data);
		printf("index: %d\n", temp->index);
		temp = temp->next;
	}
}

int	main(void)
{
	Stack	*top = NULL;

	create_stack(&top, 5, 1, 2, 3, 4, 5);
	print_stack(&top);
}