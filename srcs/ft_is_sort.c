#include "libft.h"
#include "checker.h"
#include "ft_printf.h"

int	ft_write_sort(int i)
{
	if (i == ERROR)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	else
		write(1, "OK\n", 3);
		return (1);
}

int	ft_is_sort(t_head *a, t_head *b)
{
	t_stack	*tmp;

	tmp = a->beg;
	if (b->beg != NULL)
		return (ft_write_sort(ERROR));
	if (a->beg != NULL)
	{
		while (tmp != a->end)
		{
			if (tmp->nbr > tmp->next->nbr)
				return (ft_write_sort(ERROR));
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
	return (ft_write_sort(GOOD));
}
