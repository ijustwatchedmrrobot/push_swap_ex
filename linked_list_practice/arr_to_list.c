#include <stdlib.h>
#include <stdio.h>

typedef struct linked_list
{   
    int                 data;
    struct linked_list *next;

} list;

void	insert(list **root, int data)
{
	list	*temp;
	list	*ptr;

	temp = malloc(sizeof(list));
	temp->data = data;
	temp->next = NULL;
	if (!*root)
		*root = temp;
	else
	{
		ptr = malloc(sizeof(list));
		ptr = *root;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
	}
}

list    *arr_to_list(int *arr, int	arr_size)
{
	list	*root = NULL;

	while (arr_size--)
		insert(&root, *arr++);
	return (root);
}

int main()
{
    int arr[] = {223, 45, 85, 21, 47};
	list	*root = NULL;
	int i;

	i = 5;
	root = arr_to_list(arr, 5);
	while (i--)
	{	
		printf("%d\n", root->data);
		root = root->next;
	}
}