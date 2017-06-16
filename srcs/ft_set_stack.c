/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:27:39 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/16 16:21:53 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "ft_printf.h"

int		ft_add_stack(t_head *head, char *str)
{
	t_stack	*elem;

	if ((elem = malloc(sizeof(*elem))) == NULL)
		return (-1);
	head->end->next = elem;
	elem->prev = head->end;
	head->end = elem;
	head->beg->prev = head->end;
	head->end->next = head->beg;
	if (str)
		elem->nbr = ft_atoi(str);
	elem->grp = 0;
	head->size += 1;
	return (1);
}

int		ft_init_stack(t_head *a, char *nbr)
{
	t_stack	*elem;

	elem = malloc(sizeof(*elem));
	a->beg = elem;
	a->end = elem;
	elem->next = elem;
	elem->prev = elem;
	elem->grp = 0;
	if (nbr && ft_check_if_num(nbr))
		elem->nbr = ft_atoi(nbr);
	else
		return (0);
	a->size = 1;
	return (1);
}

int		ft_set_stack(t_head **a, t_head **b, char **av)
{
	int		i;
	char	**tmp;

	tmp = NULL;
	while (*(++av))
	{
		i = 0;
		tmp = ft_strsplit(av[i], ' ');
		if ((*a)->end == NULL)
		{
			if (!ft_init_stack(*a, tmp[i]))
				return (ft_free_all(a, b, &tmp));
			++i;
		}
		while (tmp[i] != NULL)
		{
			if (!ft_check_if_num(tmp[i]) || !ft_add_stack(*a, tmp[i]))
				return (ft_free_all(a, b, &tmp));
			++i;
		}
		ft_str_multi_free(&tmp);
	}
	if (ft_no_duplicate(*a) == 0)
		return (ft_free_op(a, b));
	return (1);
}
