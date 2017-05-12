/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:12:19 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/21 19:20:38 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "checker.h"
#include "gnl.h"


void	ft_afficher(t_head *a, t_head *b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = a->beg;
	tmp_b = b->beg;
	ft_printf(RED"Stack A: "EOC);
	while (tmp_a)
	{
		ft_printf("%d ", tmp_a->nbr);
		if (tmp_a == a->end)
			break;
		tmp_a = tmp_a->next;
	}
	ft_printf("\n");
	ft_printf(RED"Stack B: "EOC);
	while (tmp_b)
	{
		ft_printf("%d ", tmp_b->nbr);
		if (tmp_b == b->end)
			break;
		tmp_b = tmp_b->next;
	}
}

int	main(int ac, char **av)
{
	char	*tab;
	t_head	*a;
	t_head	*b;

	tab = NULL;
	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		if ((ft_set_stack(&a, &b, av)) == 0)
			return (0);
		while (get_next_line2(0, &tab) > 0)
		{
			if ((ft_do_opperations(a, b, tab, 0)) == 0)
				return (0);
			free(tab);
		}
		if ((ft_is_sort(a, b)) == ERROR)
		{
			ft_write_sort(ERROR);
			ft_free_op(&a, &b);
			return (0);
		}
		ft_write_sort(GOOD);
		ft_free_op(&a, &b);
	}
	return (0);
}
