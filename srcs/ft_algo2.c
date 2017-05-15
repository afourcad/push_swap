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
#include "ft_printf.h"

int		ft_back_or_for(t_head *a, t_min *min)
{
	int		m;
	int		n;
	int		i;
	t_stack *tmp;

	m = 0;
	n = 0;
	i = 0;
	tmp = a->beg;
	if (!min->is_next)
		min->next = min->min;
	while (i++ < a->size)
	{
		if (tmp->nbr == min->min)
			break;
		++m;
		tmp = tmp->next;
	}
	i = 0;
	tmp = a->beg;
	while (i++ < a->size)
	{
		if (tmp->nbr == min->next)
			break;
		++n;
		tmp = tmp->next;
	}
	m = m > (a->size / 2) ? m - a->size : m;
	n = n > (a->size / 2) ? n - a->size : n;
	min->is_next = abs(n) < abs(m) ? 0 : 1;
	min->is_min = abs(n) < abs(m) ? 1 : 0;
	return (abs(m) <= abs(n) ? m : n);
}

void	ft_find_min(t_head *a, t_min *min)
{
	t_stack	*tmp;
	int		i;

	tmp = a->beg;
	i = 0;
	min->min = tmp->nbr;
	min->next = tmp->nbr;
	min->is_min = 1;
	min->is_next = 1;
	while (i++ < a->size)
	{
		if (tmp->nbr < min->min)
		{
			min->next = min->min;
			min->min = tmp->nbr;
		}
		if (tmp->nbr > min->min
				&& (tmp->nbr < min->next || min->next == min->min))
			min->next = tmp->nbr;
		tmp = tmp->next;
	}
	if (min->min == min->next)
		min->is_next = 0;
}

int		ft_find_operations2(t_head *a, t_head *b, char *flags)
{
	t_min	min = {.is_min = 0, .is_next = 0};
	int				goal;

	if (ft_is_partial_sort(a, b, flags))
		return (GOOD);
	ft_find_min(a, &min);
	while ((min.is_min && min.is_next) || (min.is_min && !min.is_next))
	{
		goal = ft_back_or_for(a, &min);
		if (goal == 1)
		{
			ft_do_opperations(a, b, "sa", 1);
			--goal;
		}
		else if (goal > 0)
			while (goal > 0)
			{
				ft_do_opperations(a, b, "ra", 1);
				--goal;
			}
		else if (goal < 0)
			while (goal < 0)
			{
				ft_do_opperations(a, b, "rra", 1);
				++goal;
			}
		if (goal == 0 && ((b->beg && A1 < A2) || ft_is_sort(a, NULL) != GOOD))
			ft_do_opperations(a, b, "pb", 1);
	}
	if (b->beg && b->beg->next && A2 < B2)
		ft_do_opperations(a, b, "sb", 1);
	if (ft_is_sort(a, NULL) == GOOD)
		ft_only_pa(a, b, flags);
	if (ft_is_sort(a, b) == GOOD)
		return (GOOD);
	return (ERROR);
}
