#include "libft.h"

typedef bool	(*compare_func)(int, int);

bool	greater_than(int a, int b)
{
	return (a > b);
}

bool	less_than(int a, int b)
{
	return (a < b);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int get_index_of_closest(int *element, t_list **head, compare_func compare) {
	t_list  *temp;
	int     closest[2]; // closest[0] for closest_distance, closest[1] for closest_index
	int     i;
	int     diff;

	temp = *head;
	closest[0] = -1; // closest_distance
	closest[1] = -1; // closest_index
	i = 0;
	while (temp)
	{
		if (compare(*(int *)temp->content, *element))
		{
			diff = ft_abs(*(int *)temp->content - *element);
			if (closest[1] == -1 || diff < closest[0])
			{
				closest[0] = diff;
				closest[1] = i;
			}
		}
		temp = temp->next;
		i++;
	}
	return closest[1];
}

int	get_index_of_min_and_nearest(int *element, t_list **head)
{
	int index;
	char *str;

	index = get_index_of_closest(element, head, less_than);
	str = ft_strjoin("min and nearest index is : ", "");
	if (index == -1)
	{
		index = get_index_of_max(head);
		str = ft_strjoin("max index is : ", "");
	}
	//printf("%s %i", str, index);
	return (index);
}

int	get_index_of_max_and_nearest(int *element, t_list **head)
{
	int index;
	char *str;

	index = get_index_of_closest(element, head, greater_than);
	str = ft_strjoin("max and nearest index is : ", "");
	if (index == -1)
	{
		index = get_index_of_min(head);
		str = ft_strjoin("min index", "");
	}
	//printf("%s %i", str, index);
	return (index);
}