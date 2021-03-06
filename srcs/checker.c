/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 17:12:19 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/16 16:11:51 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "checker.h"
#include "gnl.h"

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
		ft_init_head(&a, &b);
		if ((ft_set_stack(&a, &b, av)) == 0)
			return (0);
		while (get_next_line2(0, &tab) > 0)
		{
			if ((ft_do_opperations(a, b, tab, 0)) == 0)
				return (0);
			free(tab);
		}
		ft_write_sort(ft_is_sort(a, b));
		ft_free_op(&a, &b);
		return (0);
	}
	return (0);
}
