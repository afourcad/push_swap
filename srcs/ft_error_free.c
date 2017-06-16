/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:25:38 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/16 16:15:25 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "checker.h"
#include "push_swap.h"

int		ft_free_op(t_head **a, t_head **b)
{
	while ((*a)->beg != (*a)->end)
	{
		(*a)->beg = (*a)->beg->next;
		free((*a)->beg->prev);
	}
	free((*a)->beg);
	free(*a);
	if (b)
		ft_free_op(b, NULL);
	return (0);
}

int		ft_free_all(t_head **a, t_head **b, char ***tmp)
{
	ft_free_op(a, b);
	ft_str_multi_free(tmp);
	return (0);
}

int		ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

char	*ft_find_flags(char *str)
{
	int		i;
	char	*flags;

	i = 0;
	flags = NULL;
	if (str[i] == '-')
	{
		flags = ft_strnew(2);
		if (ft_atoi(str) != 0)
			return (NULL);
		while (str[++i])
		{
			if (str[i] == 'v')
				FLG_V = 1;
			else if (str[i] == 'c')
				FLG_C = 1;
			else
			{
				ft_printf("./push_swap: usage: [-vc] [numbers ...]\n");
				return (NULL);
			}
		}
	}
	return (flags);
}

void	ft_init_head(t_head **a, t_head **b)
{
	*a = malloc(sizeof(t_head));
	*b = malloc(sizeof(t_head));
	(*a)->end = NULL;
	(*a)->beg = NULL;
	(*b)->end = NULL;
	(*b)->beg = NULL;
	(*a)->size = 0;
	(*b)->size = 0;
}
