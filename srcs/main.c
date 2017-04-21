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

/*
void	affiche(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	if (tmp_a)
	{
		ft_printf("%d ", tmp_a->nbr);
		tmp_a = tmp_a->next;
	}
	while (tmp_a != *HEAD)
	{
		ft_printf("%d ", tmp_a->nbr);
		tmp_a = tmp_a->next;
	}
	ft_printf("\n");
	if (tmp_a)
	{
		ft_printf("%d ", tmp_a->nbr);
		tmp_a = tmp_a->next;
	}
	while (tmp_b != *b)
	{
		ft_printf("%d ", tmp_b->nbr);
		tmp_b = tmp_b->next;
	}
}*/
int	main(int ac, char **av)
{
	char	*tab;
	char	*flags;
	t_head	*a;
	t_head	*b;

	tab = NULL;
	a = NULL;
	b = NULL;
	flags = NULL;
	if (ac > 1)
	{
		if ((flags = ft_find_flags(av[1])) != NULL)
			++av;
		if ((ft_set_stack(&a, &b, av)) == 0
			return (0);
		while (get_next_line(0, &tab) > 0)
		{
			if ((ft_do_opperations(a, b, tab)) == 0)
				return (0);
				free(tab);
		}
		if ((ft_is_sort(a, b)) == ERROR)
			return (0);
	//	ft_afficher(a, b);
		//ft_free_op(a);
		//ft_free_op(b);
	}
	return (0);

}
