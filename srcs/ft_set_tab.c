/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 19:33:48 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/15 17:22:54 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int	ft_size_grp(t_head *head, t_tab *tab)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (head->beg)
		tab->grp = head->beg->grp;
	else
		return (0);
	tab->size = 0;
	tmp = head->beg;
	while (tmp->grp == tab->grp && i < head->size)
	{
		++(tab->size);
		tmp = tmp->next;
		++i;
	}
	return (tab->size);
}

int	ft_set_tab(t_head *head, t_tab *tab)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = head->beg;
	if ((tab->tab = malloc(sizeof(tab->tab) * tab->size)) == 0)
		return (0);
	while (i < tab->size)
	{
		(tab->tab)[i] = tmp->nbr;
		tmp = tmp->next;
		++i;
	}
	ft_quick_sort_tab(tab->tab, 0, tab->size - 1);
	return (1);
}
