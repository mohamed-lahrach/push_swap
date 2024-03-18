#include "libft.h"

int	get_element_at_index(t_list *head, int index)
{
	int i = 0;
	t_list *current = head;

	while (current != NULL)
	{
		if (i == index)
		{
			return (*((int *)current->content));
				// assuming the list stores int values
		}
		i++;
		current = current->next;
	}

	// If we get here, the index was out of bounds
	printf("Index out of bounds\n");
	return (-1);
}