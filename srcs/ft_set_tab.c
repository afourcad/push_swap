/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 19:33:48 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/07 20:14:10 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int	ft_set_tab(t_head *head, int **tab)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = head->beg;
	ft_printf("size: %d\n", head->size);
	if ((*tab = malloc(sizeof(**tab) * head->size)) == 0)
		return (0);
	while (i < head->size)
	{
		(*tab)[i] = tmp->nbr;
		ft_printf("nbr: %d\n", tmp->nbr);
		tmp = tmp->next;
		++i;
	}
	ft_quick_sort_tab(*tab, 0, head->size - 1);
	return (1);
}
