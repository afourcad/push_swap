/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:53:02 by afourcad          #+#    #+#             */
/*   Updated: 2017/05/11 18:07:53 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap.h"
#include "ft_printf.h"

int	ft_only_pa(t_head *a, t_head *b, char *flags)
{
	while (b->beg != NULL)
	{
		if (A2 > B2 || b->beg == b->end)
			ft_do_opperations(a, b, "pa", 1);
		else
			ft_do_opperations(a, b, "sb", 1);
		ft_afficher(a, b, flags);
	}
	return (ERROR);
}

void	ft_case_one(t_head *a, t_head *b)
{
	if (A1 < Z1)
	{
		if (b->beg == NULL || b->beg == b->end || A2 > Z2)
			ft_do_opperations(a, b, "pb", 1);
		else if (A2 < Z2)
			ft_do_opperations(a, b, "rrb", 1);
		else
			ft_do_opperations(a, b, "sb", 1);
	}
	else if (A1 > Z1)
	{
		if (b->beg == NULL || b->beg == b->end || A2 > Z2)
			ft_do_opperations(a, b, "rra", 1);
		else if (A2 < Z2)
			ft_do_opperations(a, b, "rrr", 1);
		else
			ft_do_opperations(a, b, "sb", 1);
	}

}

int	ft_find_operations(t_head *a, t_head *b, char *flags)
{
	if (ft_is_sort(a, NULL))
		ft_only_pa(a, b, flags);
	if (ft_is_sort(a, b) == GOOD)
		return (GOOD);
	if (a->beg == NULL || a->beg == a->end)
		return(ft_only_pa(a, b, flags));
	else if (A1 < B1)
		ft_case_one(a, b);
	else if (A1 > B1)
	{
		if (b->beg == NULL || A2 > B2)
		{
			ft_do_opperations(a, b, "sa", 1);
		}
		else
			ft_do_opperations(a, b, "ss", 1);
	}
	ft_afficher(a, b, flags);
	return (ERROR);
}
