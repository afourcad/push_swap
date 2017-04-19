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

int	ft_is_sort(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	tmp = a;
	if (b != NULL)
		return (ft_write_sort(ERROR));
	if (a != NULL)
	{
		tmp = tmp->next;
		while (tmp)
		{
			if (a->nbr > tmp->nbr)
				return (ft_write_sort(ERROR));
			tmp = tmp->next;
			a = a->next;
		}
	}
	return (ft_write_sort(GOOD));
}
