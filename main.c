/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:29:26 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 02:22:55 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sort_it(t_list **a, t_list **b)
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
			sort_it(a, b);
	}
}

char	*concatenate_arguments(int argc, char **argv)
{
	char	*str;
	int		i;

	str = NULL;
	i = 1;
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i++]);
		str = ft_strjoin(str, " ");
	}
	return (str);
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
	if (str == NULL)
		return (1);
	argv = ft_split(str, ' ');
	validate_and_sort_input(argv, &a, &b);
	free_resources(str, argv, &a, &b);
	return (0);
}
