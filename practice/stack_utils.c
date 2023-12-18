#include "../libft/libft.h"

typedef struct stack_list
{
	int					data;
	int					index;
	struct stack_list	*next;
} Stack;

void	push(Stack top, int data)
{
	Stack	*temp;
	static int index = 0;

	if (top == NULL)
	{
		top->index = -1;
		top->data = data;
		top->next = NULL;
	}
	else
	{
		temp = malloc(sizeof(Stack));
		temp->data = data;
		temp->next = top;
		temp->index = index++;
		top->next = NULL;
	}
}

void	create_stack(int *arr)
{
	stack	*temp;
	stack	*ptr;
	int	arr_size;

	arr_size = (sizeof(arr)/4);
	while (arr_size--)
		push(nums);
}