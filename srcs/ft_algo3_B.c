/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo3_B.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:52:41 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/15 18:43:42 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap.h"
#include "ft_printf.h"

void	ft_small_size(t_head *a, t_head *b, int *size, char *flags)
{
	if (A2 > B2)
	{
		ft_do_opperations(a, b, "pa", 1);
		ft_afficher(a, b, flags);
		ft_do_opperations(a, b, "pa", 1);
		ft_afficher(a, b, flags);
		*size -= 2;
		return ;
	}
	ft_do_opperations(a, b, "sb", 1);
	ft_afficher(a, b, flags);
	ft_do_opperations(a, b, "pa", 1);
	ft_afficher(a, b, flags);
	ft_do_opperations(a, b, "pa", 1);
	*size -= 2;
	ft_afficher(a, b, flags);
}

void	ft_sort_b(t_head *a, t_head *b, int *size, char *flags)
{
	if (*size < 2)
		return ;
	if (*size == 2)
	{
		ft_small_size(a, b, size, flags);
		return ;
	}
	if (A2 > B2)
	{
		if (A2 < C2)
		{
			ft_do_opperations(a, b, "rrb", 1);
			ft_afficher(a, b, flags);
		}
		ft_do_opperations(a, b, "pa", 1);
		--(*size);
		ft_afficher(a, b, flags);
	}
	else 
	{
		ft_do_opperations(a, b, "sb", 1);
		ft_afficher(a, b, flags);
	}
	ft_sort_b(a, b, size, flags);
}

void	ft_devide_in_b(t_head *a, t_head *b, t_tab *tab, char *flags)
{
	int		pivot;

	pivot = (tab->size) / 2;
	while (b->beg->grp == tab->grp)
	{
		if (b->beg->nbr > (tab->tab)[pivot])
		{
			b->beg->grp = b->beg->grp;
			ft_do_opperations(a, b, "pa", 1);
			--(tab->size);
		}
		else
		{
			b->beg->grp = b->beg->grp + 1;
			ft_do_opperations(a, b, "rb", 1);
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
		{
			ft_sort_b(a, b, &(tab.size), flags);
		}
		else
		{
			ft_set_tab(b, &tab);
			ft_devide_in_b(a, b, &tab, flags);
			free(tab.tab);
			tab.tab = NULL;
		}
	}
}
