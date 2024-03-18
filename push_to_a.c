#include "libft.h"

void	transfer_to_stack_a(t_list **a, t_list **b, int max_nearest_index)
{
	int	i;
	int	size_a;

	printf("-----------------print list a-----------------\n");
	print_list(*a);
	printf("-----------------print list b-----------------\n");
	print_list(*b);
	printf("-----------------\n");
	i = 0;
	size_a = ft_lstsize(*a);
	if (max_nearest_index <= size_a / 2)
	{
		while (i < max_nearest_index)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < size_a - max_nearest_index)
		{
			rra(a);
			i++;
		}
	}
	pb(b, a);
}

void	push_to_a(t_list **a, t_list **b)
{
	int		*element;
	int		index;
	int		i;
	t_list	*temp;
	char	*str;

	temp = *b;
	index = -1;
	i = ft_lstsize(*b);
	while (i)
	{
		element = (int *)(*b)->content;
		index = get_index_of_max_and_nearest(element, a);
		str = ft_strjoin("max nearest index", " : ");
		if (index == -1)
		{
			index = get_index_of_min(a);
			str = ft_strjoin("index of min", " ");
		}
		printf("\n\n------transfer_to_stack_a------\n");
		printf("element of stack_a %i\n", *element);
		printf("%s  %i\n", str, index);
		printf("%s  %i\n", str, get_element_at_index(*b, index));
		transfer_to_stack_a(a, b, index);
		i--;
	}
	finalize_sorting(a);
}