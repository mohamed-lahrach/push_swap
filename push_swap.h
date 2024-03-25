/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:29:23 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/24 22:05:53 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_move
{
	t_list			*temp;
	int				index_b;
	int				*best_element_to_push;
	int				index_a;
	int				move;
	int				best_move;
}					t_move;
typedef struct s_indexes
{
	int				index_a;
	int				index_b;
	int				size_a;
	int				size_b;
}					t_indexes;

char				*concatenate_arguments(int argc, char **argv);
int					get_max(int a, int b);
void				perform_operations_1(t_list **a, t_list **b, int index_a,
						int index_b);
void				perform_operations_2(t_list **a, t_list **b, int index_a,
						int index_b);
void				perform_operations_3(t_list **a, t_list **b, int index_a,
						int index_b);
void				perform_operations_4(t_list **a, t_list **b, int index_a,
						int index_b);
void				perform_operations_based_on_indexes(t_list **a, t_list **b,
						t_indexes indexes);
int					get_index_by_value(t_list *head, int value);
void				free_split(char **arr);
void				free_resources(char *str, char **argv, t_list **a,
						t_list **b);
void				push_to_b(t_list **a, t_list **b);
void				push_to_a(t_list **a, t_list **b);
int					get_index_of_min(t_list **b);
int					get_index_of_max(t_list **b);
void				finalize_sorting(t_list **a);

int					get_index_of_min_and_nearest(int element, t_list **b);
int					get_index_of_max_and_nearest(int element, t_list **b);
void				pb(t_list **head1, t_list **head2);
void				pa(t_list **head1, t_list **head2);
int					is_list_sorted_ascending(t_list *a);
void				convert_args_to_list(char **argv, t_list **a);
void				sort_three(t_list **head);
void				rra(t_list **head);
void				rrb(t_list **head);
void				rrr(t_list **head1, t_list **head2);
void				ra(t_list **head);
void				rb(t_list **head);
void				rr(t_list **head1, t_list **head2);
void				sa(t_list **head);
void				sb(t_list **head);
int					check_valid_input(char **arr);
int					check_empty_str(char **argv);
int					check_within_range(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
long				ft_atol(const char *str);
int					ft_isdigit(int c);
int					ft_lstsize(t_list *lst);
char				*ft_itoa(int n);
char				*ft_strdup(const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);

#endif
