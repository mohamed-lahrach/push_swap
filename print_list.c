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