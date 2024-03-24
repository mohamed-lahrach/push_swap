/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:28:58 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 21:26:19 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	my_strlen(const char *s)
{
	int	i;

	if (s == NULL)
	{
		return (0);
	}
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		idx;
	int		idx_join;
	char	*join;

	join = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
	if (!join)
		return (NULL);
	idx = 0;
	idx_join = 0;
	while (s1 && s1[idx])
		join[idx_join++] = s1[idx++];
	idx = 0;
	while (s2 && s2[idx])
		join[idx_join++] = s2[idx++];
	join[idx_join] = '\0';
	if (s1)
		free((void *)s1);
	return (join);
}
