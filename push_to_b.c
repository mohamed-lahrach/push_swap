#include "libft.h"

int	get_index_by_value(t_list *head, int value)
{
	int	i;

	i = 0;
	while (head)
	{
		if (*(int *)head->content == value)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
void	transfer_to_stack_b(t_list **a, t_list **b, int index_b, int *element)
{
	int	i;
	int	size_b;
	int	size_a;
	int	index_a;

	index_a = get_index_by_value(*a, *element);
	size_a = ft_lstsize(*a);
	i = 0;
	size_b = ft_lstsize(*b);
	printf("\n-----------------print list a-----------------\n");
	print_list(*a);
	printf("\n-----------------print list b-----------------\n");
	print_list(*b);
	printf("\n---------------------------------------------------------------------------------------\n");
	printf("\nindex_b min and nearest or the max : %i\n", index_b);
	printf("\nindex_a of the best element to push it to a : %i\n", index_a);
	printf("\nsiseof(a) %i\n", size_a);
	printf("\nsiseof(b) %i\n", size_b);
	printf("\nbest_element : %i\n", *element);
	// index_a and index_b are in the first half of the list
	if (index_b <= size_b / 2 && index_a <= size_a / 2)
	{
		while (index_b > 0 && index_a > 0)
		{
			rr(a, b);
			index_b--;
			index_a--;
		}
		while (index_b > 0)
		{
			rb(b);
			index_b--;
		}
		while (index_a > 0)
		{
			ra(a);
			index_a--;
		}
	}
	// index_a and index_b are in the second half of the list
	else if (index_b > size_b / 2 && index_a > size_a / 2)
	{
		index_b = size_b - index_b;
		index_a = size_a - index_a;
		while (index_b > 0 && index_a > 0)
		{
			rrr(a, b);
			index_b--;
			index_a--;
		}
		while (index_b > 0)
		{
			rrb(b);
			index_b--;
		}
		while (index_a > 0)
		{
			rra(a);
			index_a--;
		}
	}
	// index_b is in the first half and index_b is in the second half
	else if (index_b <= size_b / 2 && index_a > size_a / 2)
	{
		index_a = size_a - index_a;
		while (index_b > 0)
		{
			rb(b);
			index_b--;
		}
		while (index_a > 0)
		{
			rra(a);
			index_a--;
		}
	}
	// index_b is in the second half and index_b is in the first half
	else if (index_b > size_b / 2 && index_a <= size_a / 2)
	{
		index_b = size_b - index_b;
		while (index_b > 0)
		{
			rrb(b);
			index_b--;
		}
		while (index_a > 0)
		{
			ra(a);
			index_a--;
		}
	}
	pb(a, b);
}
int	max_index(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
int	*get_best_move_element_to_push(t_list **a, t_list **b)
{
	t_list	*temp;
	int		index_b;
	int		*best_element_to_push;
	int		index_a;
	int		move;
	int		best_move;

	index_a = 0;
	best_move = 2147483647;
	temp = *a;
	while (temp)
	{
		index_b = get_index_of_min_and_nearest((int *)temp->content, b);
		if (index_b <= ft_lstsize(*b) / 2 && index_a <= ft_lstsize(*a) / 2)
			move = max_index(index_b, index_a);
		else if (index_b > ft_lstsize(*b) / 2 && index_a > ft_lstsize(*a) / 2)
			move = max_index(ft_lstsize(*b) - index_b, ft_lstsize(*a)
					- index_a);
		else if (index_b <= ft_lstsize(*b) / 2 && index_a > ft_lstsize(*a) / 2)
			move = index_b + ft_lstsize(*a) - index_a;
		else if (index_b > ft_lstsize(*b) / 2 && index_a <= ft_lstsize(*a) / 2)
			move = (ft_lstsize(*b) - index_b) + index_a;
		if (move < best_move)
		{
			best_move = move;
			best_element_to_push = (int *)temp->content;
		}
		temp = temp->next;
		index_a++;
	}
	return (best_element_to_push);
}
void	push_to_b(t_list **a, t_list **b)
{
	int	i;
	int	index;
	int	*element;

	if (ft_lstsize(*a) == 4)
	{
		pb(a, b);
	}
	else if (ft_lstsize(*a) > 4)
	{
		pb(a, b);
		pb(a, b);
		i = ft_lstsize(*a);
		while (i > 3)
		{
			element = get_best_move_element_to_push(a, b);
			index = get_index_of_min_and_nearest(element, b);
			transfer_to_stack_b(a, b, index, element);
			i--;
		}
	}
	sort_three(a);
}
