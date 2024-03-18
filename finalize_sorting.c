#include "libft.h"

void	finalize_sorting(t_list **a)
{
	int	size_a;
	int	min_index;

	size_a = ft_lstsize(*a);
	min_index = get_index_of_min(a);
	if (!is_list_sorted_ascending(*a))
	{
		if (min_index <= size_a / 2)
		{
			while (min_index--)
			{
				ra(a);
			}
		}
		else
		{
			while (min_index++ < size_a)
			{
				rra(a);
			}
		}
	}
}