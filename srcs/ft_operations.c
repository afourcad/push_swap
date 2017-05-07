#include "libft.h"
#include "checker.h"
#include "ft_printf.h"

void	ft_swap(t_head *lst1, t_head *lst2)
{
	if (lst1->beg && lst1->beg != lst1->end)
	{
		if (lst1->end->next == lst1->beg)
		{
			lst1->beg = lst1->end;
			lst1->end = lst1->end->next;
		}
		else
		{
			lst1->beg = lst1->beg->next;
			lst1->end->next->next = lst1->beg->next;
			lst1->beg->next->prev = lst1->end->next;
			lst1->end->next = lst1->beg;
			lst1->beg->next = lst1->beg->prev;
			lst1->beg->prev = lst1->end;
			lst1->beg->next->prev = lst1->beg;
		}
	}
	if (lst2)
		ft_swap(lst2, NULL);
}

void	ft_push(t_head *lst1, t_head *lst2)
{
	if (lst1->beg)
	{
		lst2->beg = lst1->beg;
		lst2->end = lst2->end == NULL ? lst1->beg : lst2->end;
		lst1->beg = lst1->beg == lst1->end ? NULL : lst1->beg->next;
		lst1->end = lst1->end == lst2->beg ? NULL : lst1->end;
		lst2->beg->next = lst2->end == lst2->beg ? lst2->beg : lst2->end->next;
		lst2->beg->prev = lst2->end;
		lst2->end->next = lst2->beg;
		lst2->beg->next->prev = lst2->beg;
		if (lst1->beg && lst1->end)
		{
			lst1->beg->prev = lst1->end;
			lst1->end->next = lst1->beg;
		}
	}
}

void	ft_rotate(t_head *lst1, t_head *lst2)
{
	if (lst1->beg && lst1->beg != lst1->end)
	{
		lst1->beg = lst1->beg->next;
		lst1->end  = lst1->end->next;
	}
	if (lst2)
		ft_rotate(lst2, NULL);
}

void	ft_r_rotate(t_head *lst1, t_head *lst2)
{
	if (lst1->beg && lst1->beg != lst1->end)
	{
		lst1->beg = lst1->end;
		lst1->end = lst1->end->prev;
	}
	if (lst2)
		ft_r_rotate(lst2, NULL);
}

int		ft_do_opperations(t_head *a, t_head *b, char *tab)
{
	if ((ft_strcmp(tab, "sa")) == 0)
		ft_swap(a, NULL);
	else if ((ft_strcmp(tab, "sb")) == 0)
		ft_swap(b, NULL);
	else if ((ft_strcmp(tab, "ss")) == 0)
		ft_swap(a, b);
	else if ((ft_strcmp(tab, "pa")) == 0)
		ft_push(b, a);
	else if ((ft_strcmp(tab, "pb")) == 0)
		ft_push(a, b);
	else if ((ft_strcmp(tab, "ra")) == 0)
		ft_rotate(a, NULL);
	else if ((ft_strcmp(tab, "rb")) == 0)
		ft_rotate(b, NULL);
	else if ((ft_strcmp(tab, "rra")) == 0)
		ft_r_rotate(a, NULL);
	else if ((ft_strcmp(tab, "rrb")) == 0)
		ft_r_rotate(b, NULL);
	else if ((ft_strcmp(tab, "rrr")) == 0)
		ft_r_rotate(a, b);
	else if ((ft_strcmp(tab, "rr")) == 0)
		ft_rotate(a, b);
	else
		return (ft_error());
	return (1);
}
