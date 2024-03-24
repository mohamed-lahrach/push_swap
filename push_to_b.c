/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:29:50 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 21:26:19 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_operations_based_on_indexes(t_list **a, t_list **b,
		t_indexes indexes)
{
	if (indexes.index_b <= indexes.size_b / 2
		&& indexes.index_a <= indexes.size_a / 2)
		perform_operations_1(a, b, indexes.index_a, indexes.index_b);
	else if (indexes.index_b > indexes.size_b / 2
		&& indexes.index_a > indexes.size_a / 2)
	{
		indexes.index_b = indexes.size_b - indexes.index_b;
		indexes.index_a = indexes.size_a - indexes.index_a;
		perform_operations_2(a, b, indexes.index_a, indexes.index_b);
	}
	else if (indexes.index_b <= indexes.size_b / 2
		&& indexes.index_a > indexes.size_a / 2)
	{
		indexes.index_a = indexes.size_a - indexes.index_a;
		perform_operations_3(a, b, indexes.index_a, indexes.index_b);
	}
	else if (indexes.index_b > indexes.size_b / 2
		&& indexes.index_a <= indexes.size_a / 2)
	{
		indexes.index_b = indexes.size_b - indexes.index_b;
		perform_operations_4(a, b, indexes.index_a, indexes.index_b);
	}
}

void	transfer_to_stack_b(t_list **a, t_list **b, int index_b, int *element)
{
	t_indexes	indexes;

	indexes.index_a = get_index_by_value(*a, *element);
	indexes.index_b = index_b;
	indexes.size_a = ft_lstsize(*a);
	indexes.size_b = ft_lstsize(*b);
	perform_operations_based_on_indexes(a, b, indexes);
	pb(a, b);
}

int	calculate_move(int index_a, int index_b, t_list **a, t_list **b)
{
	int	move;

	move = 0;
	if (index_b <= ft_lstsize(*b) / 2 && index_a <= ft_lstsize(*a) / 2)
		move = get_max(index_b, index_a);
	else if (index_b > ft_lstsize(*b) / 2 && index_a > ft_lstsize(*a) / 2)
		move = get_max(ft_lstsize(*b) - index_b, ft_lstsize(*a) - index_a);
	else if (index_b <= ft_lstsize(*b) / 2 && index_a > ft_lstsize(*a) / 2)
		move = index_b + ft_lstsize(*a) - index_a;
	else if (index_b > ft_lstsize(*b) / 2 && index_a <= ft_lstsize(*a) / 2)
		move = (ft_lstsize(*b) - index_b) + index_a;
	return (move);
}

int	*get_best_move_element_to_push(t_list **a, t_list **b)
{
	t_move	m;

	m.temp = *a;
	m.index_a = 0;
	m.best_move = 2147483647;
	while (m.temp)
	{
		m.index_b = get_index_of_min_and_nearest(*(int *)m.temp->content, b);
		m.move = calculate_move(m.index_a, m.index_b, a, b);
		if (m.move < m.best_move)
		{
			m.best_move = m.move;
			m.best_element_to_push = (int *)m.temp->content;
		}
		m.temp = m.temp->next;
		m.index_a++;
	}
	return (m.best_element_to_push);
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
			index = get_index_of_min_and_nearest(*element, b);
			transfer_to_stack_b(a, b, index, element);
			i--;
		}
	}
	sort_three(a);
}
