/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:15:23 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/07 20:15:29 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "checker.h"
#include "push_swap.h"

void	ft_afficher_tab(int *tab, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		ft_printf("%d ",tab[i]);
		++i;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	char	*flags;
	int		*tab;
	t_head	*a;
	t_head	*b;

	a = NULL;
	b = NULL;
	flags = NULL;
	tab = NULL;
	if (ac > 1)
	{
		ft_init_head(&a, &b);
		if ((flags = ft_find_flags(av[1])) != NULL)
			++av;
		if ((ft_set_stack(&a, &b, av)) == 0 || ft_set_tab(a, &tab) == 0)
			return (0);
		ft_afficher_tab(tab, a->size);
		if (a->size <= 5)
			while ((ft_find_operations(a, b, flags)) == ERROR)
				;
		/*else
			while ((ft_algo3(a, b, flags, tab)) == ERROR)
				;*/
		ft_free_op(&a, &b);
	}
	return (0);
}
