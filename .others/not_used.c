//stack initializer with returning the address to the pointer to head
t_list	**init2(int ac, char **av)
{
	t_list	*node;
	t_list	**stack;
	char	**args;
	int		i;

	node = NULL;
	i = 0;
	stack = &node;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		push_ft(&node, ft_atoi(args[i]));
		i++;
	}
	if (ac == 2)
		free_str(args);
	return (stack);
}

//test for atoi and split (working)
static void	print_test(int ac, char **av)
{	
	char **args;
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
		ft_printf("%d\n", ft_atoi(args[i]));
		i++;
	}
}

//push with libft functions
void	push_ft(t_list **top, int content)
{
	t_list	*temp;

	temp = ft_lstnew(content);
	ft_lstadd_back(top, temp);
}

//alternative way to create stack with stdarg funcs and macros
t_list	**create_stack(int count, ...)
{
	t_list	*top;
	t_list	**root;
	va_list	args;

	top = NULL;
	root = &top;
	va_start(args, count);
	while (count--)
		push_ft(&top, va_arg(args, int));
	va_end(args);
	return (root);
}