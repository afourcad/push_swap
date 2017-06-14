/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 19:30:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/14 20:35:22 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap.h"
#include "ft_printf.h"

void	ft_sort_A(t_head *a, t_head *b, t_tab *tab, char *flags)
{
	int	i;

	i = 0;
	while ((tab->tab[i]) && (tab->tab)[i] == a->beg->nbr)
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
	else if ((tab->size - tab->rra) < tab->rra)
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
	ft_algo3_B(a, b, flags);
}

int	ft_algo3(t_head *a, t_head *b, char *flags)
{
	t_tab	tab;

	while (!ft_is_sort(a, b))
	{
		ft_size_grp(a, &tab);
		ft_set_tab(a, &tab); //trier un tab de taille ci dessus
		ft_divide_in_a(a, b, &tab, flags);//diviser avec la taille ci dessus
		ft_sort_A(a, b, &tab, flags);
		free(tab.tab);
	}
	return (GOOD);
}
