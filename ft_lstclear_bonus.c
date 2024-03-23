/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:26:29 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 01:26:32 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*p;

	if (*lst == NULL)
		return ;
	while ((*lst) != NULL)
	{
		p = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = p;
	}
	free(*lst);
	*lst = NULL;
}
