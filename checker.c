/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:08:41 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/25 00:25:46 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void ss(t_list **a, t_list **b)
{
	swap(b);
	swap(a);
}

int checker(t_list **a, t_list **b)
{
	char *line;

	if (*a == NULL)
		return 0;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_strcmp(line, "pb\n") == 0)
			push(a, b);
		else if (ft_strcmp(line, "pa\n") == 0)
			push(b, a);
		else if (ft_strcmp(line, "sa\n") == 0)
			swap(a);
		else if (ft_strcmp(line, "sb\n") == 0)
			swap(b);
		else if (ft_strcmp(line, "ss\n") == 0)
			ss(a, b);
		else if (ft_strcmp(line, "ra\n") == 0)
			rotate(a);
		else if (ft_strcmp(line, "rb\n") == 0)
			rotate(b);
		else if (ft_strcmp(line, "rr\n") == 0)
		{
			rotate(a);
			rotate(b);
		}
		else if (ft_strcmp(line, "rra\n") == 0)
			reverse_rotate(a);
		else if (ft_strcmp(line, "rrb\n") == 0)
			reverse_rotate(b);
		else if (ft_strcmp(line, "rrr\n") == 0)
		{
			reverse_rotate(a);
			reverse_rotate(b);
		}
		else
		{
			free(line);
			return 1;
		}
		free(line);
		line = get_next_line(0);
	}
	return 0;
}

void process_and_check(char **argv, char *str, t_list **a, t_list **b)
{
	if (check_valid_input(argv))
	{
		write(2, "Error\n", 6);
		free_resources(str, argv, a, b);
		return;
	}
	convert_args_to_list(argv, a);
	if (is_list_sorted_ascending(*a))
	{
		free_resources(str, argv, a, b);
		return;
	}
	if (checker(a, b) == 0)
	{
		if (*b == NULL && is_list_sorted_ascending(*a) == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}else
	{
		write(2, "Error\n", 6);
	}
	free_resources(str, argv, a, b);
}

int main(int argc, char **argv)
{
	char *str;
	t_list *a;
	t_list *b;

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
