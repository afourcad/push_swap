/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:15:23 by afourcad          #+#    #+#             */
/*   Updated: 2017/05/11 17:15:31 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "checker.h"
#include "push_swap.h"

void	ft_afficher(t_head *a, t_head *b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		i;

	tmp_a = a->beg;
	tmp_b = b->beg;
	i = 0;
	ft_printf(RED"Stack A: "EOC);
	while (i++ < a->size)
	{
		ft_printf("%d ", tmp_a->nbr);
		tmp_a = tmp_a->next;
	}
	i = 0;
	ft_printf("\n");
	ft_printf(RED"Stack B: "EOC);
	while (i++ < b->size)
	{
		ft_printf("%d ", tmp_b->nbr);
		tmp_b = tmp_b->next;
	}
	ft_printf("\n\n");
}

int	main(int ac, char **av)
{
	char	*flags;
	t_head	*a;
	t_head	*b;

	a = NULL;
	b = NULL;
	flags = NULL;
	if (ac > 1)
	{
		if ((flags = ft_find_flags(av[1])) != NULL)
			++av;
		if ((ft_set_stack(&a, &b, av)) == 0)
			return (0);
		if (a->size <= 5)
			while ((ft_find_operations(a, b, flags)) == ERROR)
				;
		else
			while ((ft_find_operations2(a, b, flags)) == ERROR)
				;
		ft_free_op(&a, &b);
	}
	return (0);
}
