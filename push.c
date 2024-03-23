/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:29:54 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 02:24:21 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push(t_list **head1, t_list **head2)
{
	t_list	*first_node;

	if (head1 == NULL)
	{
		return ;
	}
	first_node = *head1;
	*head1 = first_node->next;
	first_node->next = NULL;
	ft_lstadd_front(head2, first_node);
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
