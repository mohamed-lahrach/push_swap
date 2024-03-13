#include "libft.h"

void sort_three(t_list **a)
{

    int first;
    int second;
    int third;

    first = *(int *)(*a)->content;
    second = *(int *)(*a)->next->content;
    third = *(int *)(*a)->next->next->content;
    if (first > second && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third)
        ra(a);
    else if (first < second && first > third)
        rra(a);
    else if (first < second && second > third)
    {
        sa(a);
        ra(a);
    }
}
