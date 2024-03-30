/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_of_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:29:14 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 21:26:19 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_of_min(t_list **head_ref)
{
	int		a;
	int		i;
	int		j;
	t_list	*head;

	j = 0;
	i = 0;
	head = *head_ref;
	a = *(int *)head->content;
	while (head)
	{
		if (a > *(int *)head->content)
		{
			a = *(int *)head->content;
			i = j;
		}
		j++;
		head = head->next;
	}
	return (i);
}
