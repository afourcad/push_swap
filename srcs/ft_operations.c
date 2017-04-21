#include "libft.h"
#include "checker.h"
#include "ft_printf.h"

void	ft_swap(t_head *lst1, t_head *lst2)
{
	t_stack	*tmp;

	tmp = NULL;
	if (lst1->beg)
		if (lst1->beg->next)
		{
			tmp = lst1->beg->next;
			lst1->beg->next = tmp->next;
			tmp->next = lst1->beg;
			lst1->beg = tmp;
			lst1->beg->next->next->prev = lst1->beg->next;
			lst1>beg->next->prev = lst1->beg;
			lst!->beg->prev = lst1->end;
		}
	if (lst2)
		ft_swap(lst2, NULL);
}

void	ft_push(t_stack *lst1, t_stack *lst2)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	if (lst1->beg)
		if (*lst1)
		{
			tmp1 = lst1->beg;
			*lst1 = (*lst1)->next;
			tmp2 = *lst2;
			*lst2 = tmp1;
			tmp1->next = tmp2;
		}
}

void	ft_rotate(t_stack **lst1, t_stack **lst2)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = NULL;
	tmp2 =NULL;
	if (lst1)
		if (*lst1 && (*lst1)->next)
		{
			tmp = *lst1;
			*lst1 = tmp->next;
			tmp->next = NULL;
			tmp2 = *lst1;
			while (tmp2->next)
				tmp2 = tmp2->next;
			tmp2->next = tmp;
		}
	if (lst2)
		ft_rotate(lst2, NULL);
}

void	ft_r_rotate(t_stack **lst1, t_stack **lst2)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = NULL;
	tmp2 = NULL;
	if (lst1)
		if (*lst1 && (*lst1)->next)
		{
			tmp1 = *lst1;
			tmp2 = *lst1;
			while (tmp2->next)
				tmp2 = tmp2->next;
			*lst1 = tmp2;
			tmp2->next = tmp1;
			while (tmp1->next != tmp2)
				tmp1 = tmp1->next;
			tmp1->next = NULL;
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
