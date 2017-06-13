/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 19:30:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/13 17:33:25 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap.h"
#include "ft_printf.h"

void	ft_divide_in_a(t_head *a, t_head *b, int *tab, char *flags)
{
	int		pivot;
	int		current;

	while (a->size > 1)
	{
		pivot = (a->size) / 2;
		current = a->beg->grp;
		ft_afficher(a, b, flags);
		while (a->beg->grp == current)
		{
			if (a->beg->nbr < tab[pivot])
			{
				a->beg->grp = a->beg->grp + 2;
				ft_do_opperations(a, b, "pb", 0);
			}
			else
			{
				a->beg->grp = a->beg->grp + 1;
				ft_do_opperations(a, NULL, "ra", 0);
			}
		}
	}
}

int	ft_algo3(t_head *a, t_head *b, char *flags)
{
	int	*tab;
	int	i;

	i = 0;
	ft_set_tab(a, &tab);
	ft_divide_in_a(a, b, tab, flags);
	return (GOOD);
}
