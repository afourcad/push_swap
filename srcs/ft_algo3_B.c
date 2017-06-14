/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo3_B.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:52:41 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/14 20:41:12 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap.h"
#include "ft_printf.h"

void	ft_small_size(t_head *a, t_head *b, t_tab *tab, char *flags)
{
	if (A2 > B2)
	{
		ft_do_opperations(a, b, "pa", 1);
		ft_afficher(a, b, flags);
		ft_do_opperations(a, b, "pa", 1);
		ft_afficher(a, b, flags);
		(tab->size) -= 2;
		return ;
	}
	ft_do_opperations(a, b, "sb", 1);
	ft_afficher(a, b, flags);
	ft_do_opperations(a, b, "pa", 1);
	ft_afficher(a, b, flags);
	ft_do_opperations(a, b, "pa", 1);
	(tab->size) -= 2;
	ft_afficher(a, b, flags);
}

void	ft_sort_b(t_head *a, t_head *b, t_tab *tab, char *flags)
{
	if (tab->size < 2)
		return ;
	if (tab->size == 2)
	{
		ft_small_size(a, b, tab, flags);
		return ;
	}
	if (A2 > B2)
	{
		if (A2 < C2)
		{
			ft_do_opperations(a, b, "rra", 1);
			ft_afficher(a, b, flags);
		}
		ft_do_opperations(a, b, "pa", 1);
		--(tab->size);
		ft_afficher(a, b, flags);
	}
	else 
	{
		ft_do_opperations(a, b, "sb", 1);
		ft_afficher(a, b, flags);
	}
	ft_sort_b(a, b, tab, flags);
}

void	ft_devide_in_b(t_head *a, t_head *b, t_tab *tab, char *flags)
{
	int		pivot;

	pivot = (tab->size) / 2;
	while (b->beg->grp == tab->grp)
	{
		if (b->beg->nbr < (tab->tab)[pivot])
		{
			b->beg->grp = b->beg->grp + 1;
			ft_do_opperations(a, b, "pa", 1);
		}
		else
		{
			b->beg->grp = b->beg->grp + 2;
			ft_do_opperations(a, NULL, "rb", 1);
		}
		ft_afficher(a, b, flags);
	}
}

void	ft_algo3_B(t_head *a, t_head *b, char *flags)
{
	t_tab	tab;

	while (b->size)
	{
		if (ft_size_grp(b, &tab) < 4)
			ft_sort_b(a, b, &tab, flags);
		else
		{
			ft_set_tab(b, &tab);
			ft_devide_in_b(a, b, &tab, flags);
		}
		free(tab.tab);
	}
}
