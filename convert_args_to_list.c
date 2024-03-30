/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args_to_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:25:58 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/28 01:32:30 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert_args_to_list(char **argv, t_list **a)
{
	int		j;
	int		*num;
	t_list	*node;

	j = 0;
	while (argv[j])
	{
		num = malloc(sizeof(int));
		if (num != NULL)
		{
			*num = ft_atol(argv[j]);
			node = ft_lstnew(num);
			if (node == NULL)
			{
				free(num);
				ft_lstclear(a);
				return ;
			}
			ft_lstadd_back(a, node);
		}
		j++;
	}
}
