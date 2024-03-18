#include "libft.h"

void	transfer_to_stack_b(t_list **a, t_list **b, int min_nearest_index)
{
	int	i;
	int	size_b;

	printf("-----------------print list a-----------------\n");
	print_list(*a);
	printf("-----------------print list b-----------------\n");
	print_list(*b);
	printf("-----------------\n");
	i = 0;
	size_b = ft_lstsize(*b);
	if (min_nearest_index <= size_b / 2)
	{
		while (i < min_nearest_index)
		{
			rb(b);
			i++;
		}
	}
	else
	{
		while (i < size_b - min_nearest_index)
		{
			rrb(b);
			i++;
		}
	}
	pa(a, b);
}

void	push_to_b(t_list **a, t_list **b)
{
	int		*element;
	int		i;
	int		index;
	char	*str;

	str = NULL;
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
			str = ft_strjoin("min nearest index", " : ");
			if (index == -1)
			{
				index = get_index_of_max(b);
				str = ft_strjoin("index of max", " ");
			}
			printf("\n\n------transfer_to_stack_b------\n");
			printf("element of stack_a %i\n", *element);
			printf("%s == %i\n", str, index);
			transfer_to_stack_b(a, b, index);
			i--;
		}
	}
	sort_three(a);
}