SRC = check_empty_str.c check_valid_input.c check_within_range.c \
	ft_atol.c ft_isdigit.c ft_split.c ft_strjoin.c ft_strcmp.c  main.c\
	ft_lstnew.c ft_lstadd_front.c \
	ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c  \
	ft_lstclear.c  \
	swap.c rotate.c sort_three.c reverse_rotate.c \
	is_list_sorted_ascending.c convert_args_to_list.c \
	push.c get_index_of_closest.c  \
	push_to_b.c push_to_a.c finalize_sorting.c \
	get_index_of_max.c get_index_of_min.c free_resources.c \
	get_index_by_value.c perform_operations.c get_max.c concatenate_arguments.c\

SRC_BONUS = checker_bonus.c get_next_line.c get_next_line_utils.c \
	check_empty_str.c check_valid_input.c check_within_range.c \
	ft_atol.c ft_isdigit.c ft_split.c ft_strjoin.c ft_strcmp.c\
	ft_lstnew.c ft_lstadd_front.c \
	ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c  \
	ft_lstclear.c  \
	swap.c rotate.c sort_three.c reverse_rotate.c \
	is_list_sorted_ascending.c convert_args_to_list.c \
	push.c get_index_of_closest.c  \
	push_to_b.c push_to_a.c finalize_sorting.c \
	get_index_of_max.c get_index_of_min.c free_resources.c \
	get_index_by_value.c perform_operations.c get_max.c\
	concatenate_arguments.c ss.c\


OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
COMPLE = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
BNS = checker 

all: $(NAME)

$(NAME) : $(OBJ)
	$(COMPLE) $(FLAGS) -o $(NAME) $(OBJ)

bonus : $(BNS)

$(BNS) : $(OBJ_BONUS)
	$(COMPLE) $(FLAGS) -o $(BNS) $(OBJ_BONUS)

%.o: %.c
	$(COMPLE) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) $(BNS)
	
re: fclean all