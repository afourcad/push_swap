/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:15:23 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/21 17:00:50 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "checker.h"


void	ft_afficher(t_stack **a, t_stack **b)
{
		while (a != NULL)
		{
			ft_printf("%d ", a->nbr);
			a = a->next;
		}
		ft_printf("\n");
		while (b != NULL)
		{
			ft_printf("%d ", b->nbr);
			b = b->next;
		}
}

int	main(int ac, char **av)
{
	char	*tab;
	char	*flags;
	t_head	*a;
	t_head	*b;

	tab = NULL;
	a = NULL;
	b = NULL;
	flags == NULL;
	if (ac > 1)
	{
		if ((flags = ft_find_flags(av[1])) != NULL)
			++av;
		if ((ft_set_stack(&a, &b, av)) == 0
			return (0);
		while ((ft_find_operations(&tab));
		{
			if ((ft_do_opperations(&a, &b, tab)) == 0)
				return (0);
				free(tab);
		}
		if ((ft_is_sort(a, b)) == ERROR)
			return (0);
		ft_afficher(a, b);
		ft_free_op(a);
		ft_free_op(b);
	}
	return (0);
}
