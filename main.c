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
void sort_it(t_list **a, t_list **b)
{
    
    print_list(*a);
    print_list(*b);
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
    print_list(a);
    return 0;
}
//-2147483648 to 2147483647