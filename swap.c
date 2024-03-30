/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:30:10 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 21:26:19 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (*a != NULL && (*a)->next != NULL)
	{
		first = *a;
		second = (*a)->next;
		first->next = second->next;
		second->next = first;
		*a = second;
	}
}

void	sa(t_list **head)
{
	swap(head);
	write(1, "sa\n", 3);
}

void	sb(t_list **head)
{
	swap(head);
	write(1, "sb\n", 3);
}
