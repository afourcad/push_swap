#include "libft.h"
#include "checker.h"
#include "push_swap.h"
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
	if (b != NULL && b->beg != NULL)
		return (ERROR);
	if (a->beg != NULL)
	{
		while (tmp != a->end)
		{
			if (tmp->nbr > tmp->next->nbr)
				return (ERROR);
			tmp = tmp->next;
		}
		tmp = tmp->next;
	}
	return (GOOD);
}

int ft_partial_sort(t_head *a, t_head *b, char *flags)
{
	int	i;

	i = 0;
	if (a->size > 2)
		while (i < 2)
		{
			ft_do_opperations(a, b, "rra", 1);
			if (flags && FLG_V)
				ft_afficher(a, b, flags);
			++i;
		}
	ft_do_opperations(a, b, "sa", 1);
	ft_afficher(a, b, flags);
	i = 0;
	if (a->size > 2)
		while (i < 2)
		{
			ft_do_opperations(a, b, "ra", 1);
			ft_afficher(a, b, flags);
			++i;
		}
	ft_only_pa(a, b, flags);
	return (GOOD);
}


int	ft_is_partial_sort(t_head *a, t_head *b, char *flags)
{
	t_stack	*tmp;
	int		i;
	int		unsort;

	tmp = a->beg;
	unsort = 0;
	i = 0;
	if (b != NULL && b->beg != NULL)
		return (ERROR);
	if (a->beg != NULL)
	{
		while (i < a->size)
		{
			if (tmp->nbr > tmp->next->nbr && tmp != a->end)
				++unsort;
			if (unsort > 1)
				break ;
			tmp = tmp->next;
			++i;
		}
		if (unsort == 1 && a->beg && a->end && a->beg != a->end
				&& Z1 < a->end->prev->nbr)
			return (ft_partial_sort(a, b, flags));
	}
	return (ERROR);
}
