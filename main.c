#include "libft.h"
void print_list(t_list *head)
{
    t_list *current = head;

    while (current != NULL)
    {
        int *value = (int *)current->content;
        printf("%i\n", *value);
        current = current->next;
    }
}

int get_index_of_min_and_nearest(int *element, t_list **b)
{
    t_list *temp;

    temp = *b;
    int min_closest_distance;
    int min_closest_index;
    int i;
    int diff;
    min_closest_distance = -1;
    min_closest_index = -1;
    i = 0;
    while (temp)
    {
        if (*(int *)temp->content < element)
        {
            diff = element - *(int *)temp->content;

            if (min_closest_index == -1 || diff < min_closest_distance)
            {
                min_closest_distance = diff;
                min_closest_index = i;
            }
        }
        temp = temp->next;
        i++;
    }
    return min_closest_index;
}
void sort_it(t_list **a, t_list **b)
{
    t_list *head;

    head = *a;
    if (ft_lstsize(*a) == 4)
    {
        pa(a, b);
    }else if (ft_lstsize(*a) > 4)
    {
        pa(a, b);
        pa(a, b);
        int *element = (int *)head->content;
        printf("Element of stack a : %i\n", *element);
        printf("these are elements of stack_b\n");
        while (ft_lstsize(*a) >= 3)
        {
            int index  = get_index_of_min_and_nearest(element, b);
            printf("%i\n", index);
            pa(a, b);
        }
    }
    
    
}
void validate_and_sort_input(char **argv, t_list **a, t_list **b)
{
    if (check_valid_input(argv))
    {
        write(1, "Error\n", 6);
        return;
    }
    convert_args_to_list(argv, a);
    if (is_list_sorted_ascending(*a))
        write(0, "Error\n", 6);
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
int main(int argc, char **argv)
{

    char *str;
    int i;
    t_list *a;
    t_list *b;

    b = NULL;
    a = NULL;
    str = NULL;
    i = 1;
    if (check_empty_str(argv))
    {
        fprintf(stderr, "Error\n");
        return 1;
    }
    while (i < argc)
    {
        str = ft_strjoin(str, argv[i++]);
        str = ft_strjoin(str, " ");
    }
    if (str == NULL)
        return 1;
    argv = ft_split(str, ' ');
    validate_and_sort_input(argv, &a, &b);
    // print_list(a);
    // printf("\n---------------------------------------\n");
    // print_list(b);
    return 0;
}
//-2147483648 to 2147483647