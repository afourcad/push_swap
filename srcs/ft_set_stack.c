/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:27:39 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/14 19:04:08 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"
#include "ft_printf.h"

t_stack	*ft_new_op(char	*str)
{
	t_stack	*list;

	list = malloc(sizeof(*list));
	list->nbr = ft_strdup(str);
	list->next = NULL;
	return (list);
}

void	ft_add_op(t_stack **lst, char *str)
{
	if (*lst == NULL)
	{
		*lst = ft_new_op(str);
		return ;
	}
	ft_add_op(&(*lst)->next, str);
}

void	ft_set_stack(t_stack **a, t_stack **b, int ac, char **av)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = NULL;
	while (av[++i])
	{
		tmp = ft_strsplit(av[i], ' ');
		while (*tmp)
		{
	ft_printf("%s ", *tmp);
			ft_add_op(a, *tmp);
			++tmp;
		}
		//ft_strfree(*tmp); bug complet lololololol
	}
}
