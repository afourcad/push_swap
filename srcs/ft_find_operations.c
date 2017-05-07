/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:53:02 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/20 17:21:11 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap.h"
#include "ft_printf.h"

int	ft_only_pa(t_head *a, t_head *b, char *flags)
{
(void)flags;
	while (b->beg != NULL)
	{
		if (A2 > B2 || b->beg == b->end)
			ft_do_opperations(a, b, "pa");
		else
			ft_do_opperations(a, b, "sb");
		ft_afficher(a, b);
	}
	return (ERROR);
}
int	ft_find_operations(t_head *a, t_head *b, char *flags)
{
	(void)flags;
	if (ft_is_sort(a, b) == GOOD)
		return (GOOD);
	if (a->beg == NULL || a->beg == a->end)
		ft_only_pa(a, b, flags);
	else if (A1 < B1 && (b->beg == NULL || b->beg == b->end || A2 > B2))
	{
		if (A1 < Z1)
		{
			if (b->beg == NULL || b->beg == b->end || A2 > Z2)
			{
				ft_do_opperations(a, b, "pb");
				}
			else if (A2 < Z2)
				ft_do_opperations(a, b, "rrb");
			else
				ft_do_opperations(a, b, "sb");
		}
		else if (A1 > Z1)
		{
			if (b->beg == NULL || A2 > Z2)
				ft_do_opperations(a, b, "rra");
			else if (A2 < Z2)
				ft_do_opperations(a, b, "rrr");
			else
				ft_do_opperations(a, b, "sb");
		}
	}
	else if (A1 > B1)
	{
		if (b->beg == NULL || A2 > B2)
		{
			ft_do_opperations(a, b, "sa");
			}
		else
			ft_do_opperations(a, b, "ss");
	}
	ft_afficher(a,b);
	ft_printf("\n");
	return (ERROR);
}
