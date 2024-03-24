/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 03:16:05 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 21:26:19 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_operations_1(t_list **a, t_list **b, int index_a, int index_b)
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

void	perform_operations_2(t_list **a, t_list **b, int index_a, int index_b)
{
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

void	perform_operations_3(t_list **a, t_list **b, int index_a, int index_b)
{
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

void	perform_operations_4(t_list **a, t_list **b, int index_a, int index_b)
{
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
