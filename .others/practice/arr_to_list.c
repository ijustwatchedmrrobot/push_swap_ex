#include <stdlib.h>
#include <stdio.h>


// Struct for the nodes of linked lists, contains data and the adress of the next node
typedef struct linked_list
{   
    int                 data;
    struct linked_list *next;

} list;


//function for insertion & creation
//takes the address of the root node and the data
//first step - create a temp. node
//if the root's NULL, (which is NULL for the first calling of the function), assign the temp into root
//if the root's FULL, allocate a memory for ptr (which is another temp. for go to last node), 
//assign the root into ptr and go to last node
//then just assign temp into last node's ->next
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

//root->temp1->temp2...

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
	root = arr_to_list(arr, (sizeof(arr)/4));
	while (i--)
	{	
		printf("%d\n", root->data);
		root = root->next;
	}
}
