/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:25:38 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/21 16:27:12 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "checker.h"
#include "push_swap.h"

void	ft_free_op(t_head **a, t_head **b)
{
	t_stack	*tmp;

	tmp = (*a)->beg;
	while (tmp)
	{
		if (tmp->next != (*a)->beg)
		{
			tmp = tmp->next;
			free (tmp->prev);
		}
		else
		{
			free(tmp);
			break;
		}
	}
	free(a);
	if (b)
		ft_free_op(b, NULL);
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
	flags = ft_strnew(2);
	if (str[i] == '-')
		while (str[++i])
		{
			if (str[i] == 'v')
				FLG_V = 1;
			else if (str[i] == 'c')
				FLG_C = 1;
			else
			{
				ft_printf("./push_swap:  usage: [-vc] [numbers ...]\n");
				return (NULL);
			}
		}
	return (flags);
}

