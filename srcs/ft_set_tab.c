/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 19:33:48 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/14 20:43:00 by afourcad         ###   ########.fr       */
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

	if (head->beg && (head->beg->grp == 0 || head->beg->grp == 2))
	{
		tab->grp = head->beg->grp == 0 ? 0 : 2;
		tab->size = head->size;
		return (tab->size);
	}
	else if (head->beg)
		tab->grp = head->beg->grp;
	else
		return (0);
	tab->size = 0;
	tmp = head->beg;
	while (tmp->grp == tab->grp)
	{
		write(1, "yo\n", 3);
		++(tab->size);
		tmp = tmp->next;
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
