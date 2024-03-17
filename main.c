#include "libft.h"

void	print_list(t_list *head)
{
	t_list	*current;
	int		*value;

	current = head;
	while (current != NULL)
	{
		value = (int *)current->content;
		printf("%i\n", *value);
		current = current->next;
	}
}
int	get_index_of_max(t_list **b)
{
	t_list	*temp;
	int		max_value;
	int		max_index;
	int		i;
	int		current_value;

	temp = *b;
	max_value = -2147483648;
	max_index = 0;
	i = 0;
	while (temp)
	{
		current_value = *(int *)temp->content;
		if (current_value > max_value)
		{
			max_value = current_value;
			max_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (max_index);
}
int	get_index_of_min(t_list **b)
{
	t_list	*temp;
	int		min_value;
	int		min_index;
	int		i;
	int		current_value;

	temp = *b;
	min_value = 2147483647;
	min_index = 0;
	i = 0;
	while (temp)
	{
		current_value = *(int *)temp->content;
		if (current_value < min_value)
		{
			min_value = current_value;
			min_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (min_index);
}
void	transfer_to_stack_b(t_list **a, t_list **b, int max_nearest_index)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*b);
	printf("size of stack b == %i\n", size);
	printf("size of stack a == %i\n", ft_lstsize(*a));
	printf("size of stack b / 2 == %i\n", size / 2);
	printf("size of stack b - min_nearest_index == %i\n", size
		- max_nearest_index);
	printf("min nearest index == %i\n", max_nearest_index);
	if (max_nearest_index < size / 2)
		while (i++ < max_nearest_index)
			rb(b);
	else
		while (i++ < size - max_nearest_index)
			rrb(b);
	pb(a, b);
}

void	push_to_b(t_list **a, t_list **b)
{
	int	*element;
	int	i;
	int	index;

	if (ft_lstsize(*a) == 4)
	{
		pa(a, b);
	}
	else if (ft_lstsize(*a) > 4)
	{
		pa(a, b);
		pa(a, b);
		i = ft_lstsize(*a);
		while (i > 3)
		{
			element = (int *)(*a)->content;
			index = get_index_of_min_and_nearest(element, b);
			if (index == -1)
			{
				index = get_index_of_max(b);
			}
			printf("\n\n------transfer_to_stack_b------\n");
			printf("element of stack_a %i\n", *element);
			transfer_to_stack_b(a, b, index);
			i--;
		}
	}
	sort_three(a);
}
void	transfer_to_stack_a(t_list **a, t_list **b, int max_nearest_index)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*a);
	(void)a;
	(void)b;
	printf("size of stack a == %i\n", size);
	printf("size of stack b == %i\n", ft_lstsize(*b));
	printf("size of stack a / 2 == %i\n", size / 2);
	printf("size - max_nearest_index == %i\n", size - max_nearest_index);
	printf("max nearest index == %i\n", max_nearest_index);
	if (max_nearest_index < size / 2)
		while (i++ < max_nearest_index)
			ra(a);
	else
		while (i++ < size - max_nearest_index)
			rra(a);
	pb(b, a);
}

void	push_to_a(t_list **a, t_list **b)
{
	int		*element;
	int		index;
	int		i;
	t_list	*temp;

	(void)a;
	temp = *b;
	index = -1;
	i = ft_lstsize(*b);
	while (i)
	{
		element = (int *)(temp)->content;
		index = get_index_of_max_and_nearest(element, a);
		if (index == -1)
		{
			index = get_index_of_min(b);
		}
		printf("\n\n------transfer_to_stack_a------\n");
		printf("element of stack_b %i\n", *element);
		transfer_to_stack_a(a, b, index);
		i--;
	}
}
void	sort_it(t_list **a, t_list **b)
{
	printf("-----------------push to b-----------------\n");
	push_to_b(a, b);
	printf("-----------------push to a-----------------\n");
	push_to_a(a, b);
}
void	validate_and_sort_input(char **argv, t_list **a, t_list **b)
{
	if (check_valid_input(argv))
	{
		write(1, "Error\n", 6);
		return ;
	}
	convert_args_to_list(argv, a);
	if (is_list_sorted_ascending(*a))
		write(0, "Error\n", 6);
	else
	{
		if (ft_lstsize(*a) == 2)
			sa(a);
		else if (ft_lstsize(*a) == 3)
		{
			sort_three(a);
		}
		else
			sort_it(a, b);
	}
}
int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = NULL;
	str = NULL;
	i = 1;
	if (check_empty_str(argv))
	{
		fprintf(stderr, "Error\n");
		return (1);
	}
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i++]);
		str = ft_strjoin(str, " ");
	}
	if (str == NULL)
		return (1);
	argv = ft_split(str, ' ');
	validate_and_sort_input(argv, &a, &b);
	printf("\n-------------------Mian--------------------\n");
	printf("--------------------stack_a------------------\n");
	print_list(a);
	printf("\n---------------------------------------\n");
	printf("--------------------stack_b------------------\n");
	print_list(b);
	return (0);
}
//-2147483648 to 2147483647