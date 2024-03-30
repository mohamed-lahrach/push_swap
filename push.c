/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:29:54 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/24 02:03:30 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **head, t_list **p)
{
	t_list	*a;

	if (*head == NULL)
		return ;
	a = *head;
	*head = a->next;
	a->next = NULL;
	ft_lstadd_front(p, a);
}

void	pb(t_list **head1, t_list **head2)
{
	push(head1, head2);
	write(1, "pb\n", 3);
}

void	pa(t_list **head1, t_list **head2)
{
	push(head1, head2);
	write(1, "pa\n", 3);
}
