#include "libft.h"

void convert_args_to_list(char **argv, t_list **a)
{
    int j = 0;
    while (argv[j])
    {
        int *num = malloc(sizeof(int));
        if (num != NULL)
        {
            *num = ft_atol(argv[j]);
            t_list *node = ft_lstnew(num);
            ft_lstadd_back(a, node);
        }
        j++;
    }
}