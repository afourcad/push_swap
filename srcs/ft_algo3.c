/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 19:30:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/16 16:16:42 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap.h"
#include "ft_printf.h"

void	ft_size_tree_or_two(t_head *a, t_head *b, char *flags, int size_grp)
{
	if (size_grp == 2)
	{
		ft_do_opperations(a, b, "pb", 1);
		ft_afficher(a, b, flags);
		ft_do_opperations(a, b, "pb", 1);
		ft_afficher(a, b, flags);
		ft_small_size(a, b, &size_grp, flags);
	}
	else
	{
		ft_do_opperations(a, b, "pb", 1);
		ft_afficher(a, b, flags);
		ft_do_opperations(a, b, "pb", 1);
		ft_afficher(a, b, flags);
		ft_do_opperations(a, b, "pb", 1);
		ft_afficher(a, b, flags);
		ft_sort_b(a, b, &size_grp, flags);
	}
}

void	ft_sort_a(t_head *a, t_head *b, t_tab *tab, char *flags)
{
	int	i;

	i = 0;
	while (i < tab->size && (tab->tab)[i] == a->beg->nbr)
	{
		ft_do_opperations(a, NULL, "ra", 1);
		ft_afficher(a, b, flags);
		++i;
	}
}

void	ft_ra_back(t_head *a, t_head *b, t_tab *tab, char *flags)
{
	if (tab->grp == 0)
		return ;
	else if ((a->size - tab->rra) < tab->rra)
		while (tab->size)
		{
			ft_do_opperations(a, NULL, "ra", 1);
			--(tab->size);
			ft_afficher(a, b, flags);
		}
	else
		while (tab->rra)
		{
			ft_do_opperations(a, NULL, "rra", 1);
			--(tab->rra);
			ft_afficher(a, b, flags);
		}
}

void	ft_divide_in_a(t_head *a, t_head *b, t_tab *tab, char *flags)
{
	int		pivot;

	tab->rra = 0;
	pivot = (tab->size) / 2;
	while (a->beg->grp == tab->grp)
	{
		if (a->beg->nbr < (tab->tab)[pivot])
		{
			a->beg->grp = a->beg->grp + 2;
			ft_do_opperations(a, b, "pb", 1);
		}
		else
		{
			a->beg->grp = a->beg->grp + 1;
			ft_do_opperations(a, b, "ra", 1);
			++(tab->rra);
		}
		ft_afficher(a, b, flags);
	}
	ft_ra_back(a, b, tab, flags);
	ft_algo3_b(a, b, flags);
}

int		ft_algo3(t_head *a, t_head *b, char *flags)
{
	t_tab	tab;
	int		size_grp;

	while (!ft_is_sort(a, b))
	{
		if ((size_grp = ft_size_grp(a, &tab)) < 4)
		{
			ft_size_tree_or_two(a, b, flags, size_grp);
			ft_set_tab(a, &tab);
			ft_sort_a(a, b, &tab, flags);
		}
		else
		{
			ft_set_tab(a, &tab);
			ft_divide_in_a(a, b, &tab, flags);
			ft_sort_a(a, b, &tab, flags);
		}
		free(tab.tab);
		tab.tab = NULL;
	}
	return (GOOD);
}
