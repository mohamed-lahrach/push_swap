/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:29:26 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/25 00:53:03 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **a, t_list **b)
{
	push_to_b(a, b);
	push_to_a(a, b);
}

void	validate_and_sort_input(char **argv, t_list **a, t_list **b)
{
	if (check_valid_input(argv))
	{
		write(2, "Error\n", 6);
		return ;
	}
	convert_args_to_list(argv, a);
	if (is_list_sorted_ascending(*a))
	{
		return ;
	}
	else
	{
		if (ft_lstsize(*a) == 2)
			sa(a);
		else if (ft_lstsize(*a) == 3)
		{
			sort_three(a);
		}
		else
			sort_stack(a, b);
	}
}

int	check_and_free(char *str)
{
	if (str == NULL)
	{
		free(str);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = NULL;
	str = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	if (check_empty_str(argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	str = concatenate_arguments(argc, argv);
	if (check_and_free(str))
		return (1);
	argv = ft_split(str, ' ');
	validate_and_sort_input(argv, &a, &b);
	free_resources(str, argv, &a, &b);
	return (0);
}
