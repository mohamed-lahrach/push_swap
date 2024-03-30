/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:08:41 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/28 02:05:31 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"

int	check_other(t_list **a, t_list **b, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		rotate(a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(b);
	else if (ft_strcmp(str, "rr\n") == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strcmp(str, "rra\n") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(str, "rrr\n") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
	{
		free(str);
		get_next_line(-1);
		return (1);
	}
	return (0);
}

int	checker(t_list **a, t_list **b)
{
	char	*str;

	if (*a == NULL)
		return (0);
	str = get_next_line(0);
	while (str != NULL)
	{
		if (ft_strcmp(str, "pb\n") == 0)
			push(a, b);
		else if (ft_strcmp(str, "pa\n") == 0)
			push(b, a);
		else if (ft_strcmp(str, "sa\n") == 0)
			swap(a);
		else if (ft_strcmp(str, "sb\n") == 0)
			swap(b);
		else if (ft_strcmp(str, "ss\n") == 0)
			ss(a, b);
		else if (check_other(a, b, str) == 1)
			return (1);
		free(str);
		str = get_next_line(0);
	}
	return (0);
}

void	check_and_write(t_list **a, t_list **b)
{
	if (checker(a, b) == 0)
	{
		if (*b == NULL && is_list_sorted_ascending(*a) == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(2, "Error\n", 6);
}

void	process_and_check(char **argv, char *str, t_list **a, t_list **b)
{
	if (check_valid_input(argv))
	{
		write(2, "Error\n", 6);
		free_resources(str, argv, a, b);
		return ;
	}
	convert_args_to_list(argv, a);
	if (*a == NULL)
	{
		free_resources(str, argv, a, b);
		return ;
	}
	if (is_list_sorted_ascending(*a))
	{
		write(1, "OK\n", 3);
		free_resources(str, argv, a, b);
		return ;
	}
	check_and_write(a, b);
	free_resources(str, argv, a, b);
}

int	main(int argc, char **argv)
{
	char	*str;
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = NULL;
	str = NULL;
	if (argc == 1)
		return (0);
	if (check_empty_str(argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	str = concatenate_arguments(argc, argv);
	if (str == NULL)
	{
		free(str);
		return (1);
	}
	argv = ft_split(str, ' ');
	process_and_check(argv, str, &a, &b);
	return (0);
}
