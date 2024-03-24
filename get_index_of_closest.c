/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_of_closest.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:29:07 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 21:26:19 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_of_min_and_nearest(int element, t_list **head)
{
	int		i;
	int		j;
	t_list	*new;
	int		p;

	i = 0;
	new = *head;
	j = -1;
	p = -2147483648;
	while (new)
	{
		if (*(int *)new->content < element && *(int *)new->content >= p)
		{
			p = *(int *)new->content;
			j = i;
		}
		i++;
		new = new->next;
	}
	if (j == -1)
	{
		j = get_index_of_max(head);
	}
	return (j);
}

int	get_index_of_max_and_nearest(int element, t_list **head)
{
	int		i;
	int		index_of_max_nearest;
	t_list	*new;
	long	p;

	index_of_max_nearest = -1;
	i = 0;
	new = *head;
	p = 2147483648;
	while (new)
	{
		if (*(int *)(new->content) > element && *(int *)(new->content) < p)
		{
			p = *(int *)(new->content);
			index_of_max_nearest = i;
		}
		i++;
		new = new->next;
	}
	if (index_of_max_nearest == -1)
	{
		index_of_max_nearest = get_index_of_min(head);
	}
	return (index_of_max_nearest);
}
