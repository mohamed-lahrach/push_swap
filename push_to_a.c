/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:29:43 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 21:26:19 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	transfer_to_stack_a(t_list **a, t_list **b, int index_a)
{
	int	i;
	int	size_a;

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

	temp = *b;
	index = -1;
	i = ft_lstsize(*b);
	while (i)
	{
		element = (int *)(*b)->content;
		index = get_index_of_max_and_nearest(*element, a);
		transfer_to_stack_a(a, b, index);
		i--;
	}
	finalize_sorting(a);
}
