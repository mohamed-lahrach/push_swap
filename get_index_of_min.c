#include "libft.h"

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