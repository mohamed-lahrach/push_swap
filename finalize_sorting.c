/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:26:03 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 21:26:19 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
