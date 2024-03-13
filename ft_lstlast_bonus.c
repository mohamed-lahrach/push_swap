#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;
	int		i;
	int		a;

	last = NULL;
	i = ft_lstsize(lst);
	a = 0;
	while (a != i)
	{
		last = lst;
		a++;
		lst = lst->next;
	}
	return (last);
}
