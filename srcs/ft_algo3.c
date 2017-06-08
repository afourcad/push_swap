/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 19:30:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/08 18:17:36 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap.h"
#include "ft_printf.h"

void	ft_divide_in_a(t_head *a, t_head *b, int *tab)
{
	int	pivot;

	pivot = (a->size) / 2;

}

int	ft_algo3(t_head *a, t_head *b, char *flags)
{
	int	*tab;

	ft_set_tab(a, &tab);
	ft_divide_in_a(a, b, tab);
}
