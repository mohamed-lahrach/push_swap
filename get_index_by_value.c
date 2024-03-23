/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index_by_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:34:01 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 02:38:06 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_index_by_value(t_list *head, int value)
{
	int	i;

	i = 0;
	while (head)
	{
		if (*(int *)head->content == value)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
