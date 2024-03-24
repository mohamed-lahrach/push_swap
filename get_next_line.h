/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:55:31 by aabdenou          #+#    #+#             */
/*   Updated: 2024/03/24 20:28:01 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "push_swap.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		check_others(t_list **a, t_list **b, char *str);
void	checker(t_list **a, t_list **b);
size_t	ft_strlen(char *str);
int		find_char_in_string(const char *s, int c);
char	*get_next_line(int fd);
void	reverse_rotate(t_list **a);
void	push(t_list **head1, t_list **head2);
void	swap(t_list **head);
void	rotate(t_list **head);
void	reverse_rotate(t_list **a);
#endif
