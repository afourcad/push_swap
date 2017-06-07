/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:13:23 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/07 20:23:45 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_quick_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_quick_sort_tab(int *tab, int min, int max)
{
	int	pivot;
	int	left;
	int	right;

	if (min < max)
	{
		pivot = min;
		left = min;
		right = max;
		while (left < right)
		{
			while (left < max && tab[left] <= tab[pivot])
				++left;
			while (right > min && tab[right] > tab[pivot])
				--right;
			if (left < right)
				ft_quick_swap(&tab[left], &tab[right]);
		}
		ft_quick_swap(&tab[right], &tab[pivot]);
		ft_quick_sort_tab(tab, min, right - 1);
		ft_quick_sort_tab(tab, right + 1, max);
	}
}
