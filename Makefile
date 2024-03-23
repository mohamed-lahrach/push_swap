SRC = check_empty_str.c check_valid_input.c check_within_range.c \
	ft_atol.c ft_isdigit.c ft_split.c ft_strjoin.c ft_strcmp.c  main.c\
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c  \
	ft_lstclear_bonus.c  \
	swap.c rotate.c sort_three.c reverse_rotate.c \
	is_list_sorted_ascending.c convert_args_to_list.c \
	push.c get_index_of_closest.c  \
	push_to_b.c push_to_a.c finalize_sorting.c \
	get_index_of_max.c get_index_of_min.c free_resources.c \
	get_index_by_value.c perform_operations.c get_max.c\

OBJ = $(SRC:.c=.o)
COMPLE = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
$(NAME) : $(OBJ)
	$(COMPLE) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(COMPLE) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	
re: fclean all