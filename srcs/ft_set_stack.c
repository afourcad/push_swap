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

	if ((list = malloc(sizeof(*list))) == NULL)
		return (NULL);
	if ((list->nbr = ft_strdup(str)) == NULL)
	{
		free(list);
		return (NULL);
	}
	list->next = NULL;
	return (list);
}

int		ft_add_stack(t_stack **lst, char *str)
{
	if (*lst == NULL)
	{
		if ((*lst = ft_new_op(str)) == NULL)
			return (0);
		return (1);
	}
	return (ft_add_stack(&(*lst)->next, str));
}

int		ft_check_if_num(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (ft_error());
	}
	return (1);
}

int		ft_no_duplicate(t_stack *a, char *nbr)
{
	t_stack	*tmp;

	tmp = a;
	if (a->next == NULL)
		return (1);
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if ((ft_strcmp(nbr, tmp->nbr)) == 0)
			return (ft_error());
		tmp = tmp->next;
	}
	return (ft_no_duplicate(a->next, a->next->nbr));
}

int		ft_set_stack(t_stack **a, char **av)
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
			if ((ft_check_if_num(*tmp)) == 0)
				return (0);
			if ((ft_add_stack(a, *tmp)) == 0)
				return (0);
			++tmp;
		}
		//ft_strfree(*tmp); bug complet lololololol
	}
	ft_printf("%s\n", av[i]);
	if ((ft_no_duplicate(*a, (*a)->nbr)) == 0)
		return (0);
	return (1);
}
