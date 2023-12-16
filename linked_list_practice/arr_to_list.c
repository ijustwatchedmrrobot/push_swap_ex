#include <stdlib.h>
#include <stdio.h>

typedef struct linked_list
{   
    int                 data;
    struct linked_list *next;

} list;

list    *lstnew(int data)
{
    list    *node;
    
	node = malloc(sizeof(list));
    if (!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    return (node);
}

list	*lstlast(list *lst)
{
	list	*temp;	
	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void    arr_to_list(int *arr, list **root)
{
	list	*temp;
	*root = lstnew(*arr++);
	while (*arr)
	{
		lstlast(*root)->next = lstnew(*arr);
		*root = (*root)->next;
		arr++;
	}
}

int main()
{
    int arr[] = {223, 45, 85, 21, 47};
	list	*root = NULL;
	arr_to_list(arr, &root);
	while (root)
	{	
		printf("%d\n", root->data);
		root = root->next;
	}
}