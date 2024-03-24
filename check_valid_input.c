/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:25:26 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 21:26:19 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate_digits(char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_strcmp(arr[i], arr[j]) == 0)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_special_chars_or_letters(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (j == 0 && (arr[i][j] == '-' || arr[i][j] == '+'))
			{
				j++;
				continue ;
			}
			if (!ft_isdigit((unsigned char)arr[i][j]) || arr[i][j] == '\t')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_valid_input(char **arr)
{
	int	i;
	int	valid;

	i = 0;
	valid = 1;
	if (check_special_chars_or_letters(arr))
		valid = 0;
	else if (check_duplicate_digits(arr))
		valid = 0;
	else
	{
		while (arr[i])
		{
			if (!check_within_range(arr[i]))
			{
				valid = 0;
				break ;
			}
			i++;
		}
	}
	if (valid)
		return (0);
	else
		return (1);
}
