#include "libft.h"

void	transfer_to_stack_a(t_list **a, t_list **b, int index_a)
{
	int	i;
	int	size_a;

	printf("\n-----------------print list a-----------------\n");
	print_list(*a);
	printf("\n-----------------print list b-----------------\n");
	print_list(*b);
	printf("\n---------------------------------------------------------------\n");
	printf("\nindex_a : %i\n", index_a);
	i = 0;
	size_a = ft_lstsize(*a);
	if (index_a <= size_a / 2)
	{
		while (i < index_a)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < size_a - index_a)
		{
			rra(a);
			i++;
		}
	}
	pa(b, a);
}

void	push_to_a(t_list **a, t_list **b)
{
	int		*element;
	int		index;
	int		i;
	t_list	*temp;
	//char	*str;

	temp = *b;
	index = -1;
	i = ft_lstsize(*b);
	while (i)
	{
		element = (int *)(*b)->content;
		printf("\n------transfer_to_stack_a------\n");
		printf("element of stack_b %i\n", *element);
		index = get_index_of_max_and_nearest(element, a);
		printf("%s  %i\n", "index of element", index);
		printf("%s  %i\n", "get  element by index", get_element_at_index(*b, index));
		transfer_to_stack_a(a, b, index);
		i--;
	}
	finalize_sorting(a);
}