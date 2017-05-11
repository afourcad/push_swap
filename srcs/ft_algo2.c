/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:13:50 by afourcad          #+#    #+#             */
/*   Updated: 2017/05/11 18:09:36 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "checker.h"
#include "push_swap.h"

int		ft_back_or_for(t_head *a, int min[1])
{
	int		forw;
	int		back;
	t_stack *tmp_f;
	t_stack	*tmp_b;

	forw = 0;
	back = 0;
	tmp_f = a->beg;
	tmp_b = a->beg;
	while (tmp_f->next != a->beg && tmp_b->prev != a->beg)
	{
		if (tmp_f->nbr != min[0] && tmp_f->nbr != min[1])
			++forw;
		else
			return (forw);
		if (tmp_b->nbr != min[0] && tmp_b->nbr != min[1])
			--back;
		else
			return (back);
		tmp_f = tmp_f->next;
		tmp_b = tmp_b->prev;
	}
	return (0);
}

void	ft_find_min(t_head *a, int min[1])
{
	t_stack	*tmp;

	tmp = a->beg;
	min[0] = tmp->nbr;
	min[1] = tmp->next->nbr;
	while (tmp->next != a->beg)
	{
		if (tmp->nbr < min[0])
			min[0] = tmp->nbr;
		if (tmp->nbr > min[0] && tmp->nbr < min[1])
			min[1] = tmp->nbr;
		tmp = tmp->next;
	}
}

int		ft_find_operations2(t_head *a, t_head *b, char *flags)
{
	int	min[1];
	int	goal;

	ft_find_min(a, min);
	goal = ft_back_or_for(a, min);
	if (goal-- == 1)
		ft_do_opperations(a, b, "sa");
	if (goal > 0)
		while (goal-- > 0)
			ft_do_opperations(a, b, "ra");
	else if (goal < 0)
		while (goal-- < 0)
			ft_do_opperations(a, b, "rra");
	if (goal == 0 && ft_is_sort(a, NULL) != GOOD)
		ft_do_opperations(a, b, "pb");
	if (ft_is_sort(a, b) == GOODD)
		return (GOOD);
	return (ERROR);
}
