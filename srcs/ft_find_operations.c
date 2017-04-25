/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:53:02 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/20 17:21:11 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "push_swap.h"
#include "ft_printf.h"

int	ft_find_operations(t_head *a, t_head *b, char *flags)
{

	(void)flags;
	if (ft_is_sort(a, b) == GOOD)
		return (GOOD);
	if (AA < AB)
	{
		if (AA < AZ)
			ft_do_opperations(a, b, "pa");
		else
			ft_do_opperations(a, b, "rra");
	}
	else
		ft_do_opperations(a, b, "sa");
	return (ERROR);
}
