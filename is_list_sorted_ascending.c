#include "libft.h"

int is_list_sorted_ascending(t_list *a)
{
    if (a == NULL)
        return 1;
    while (a->next != NULL)
    {
        int *current_value = (int *)a->content;
        int *next_value = (int *)a->next->content;

        if (*current_value > *next_value)
            return 0;

        a = a->next;
    }
    return 1;
}