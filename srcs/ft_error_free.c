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

void	ft_free_op(t_stack *param)
{
	if (param == NULL)
		return ;
	ft_free_op(param->next);
	free(param);
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

