#include "libft.h"
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