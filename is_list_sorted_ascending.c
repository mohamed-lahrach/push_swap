/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_list_sorted_ascending.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:29:17 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 21:26:19 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_list_sorted_ascending(t_list *a)
{
	int	*current_value;
	int	*next_value;

	if (a == NULL)
		return (1);
	while (a->next != NULL)
	{
		current_value = (int *)a->content;
		next_value = (int *)a->next->content;
		if (*current_value > *next_value)
			return (0);
		a = a->next;
	}
	return (1);
}
