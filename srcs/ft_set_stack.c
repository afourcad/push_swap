/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:27:39 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/21 19:10:54 by afourcad         ###   ########.fr       */
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
	head->size += 1;
	return(1);
}

void	ft_init_stack(t_head *a, char *nbr)
{
	t_stack	*elem;

	elem = malloc(sizeof(*elem));
	a->beg = elem;
	a->end = elem;
	elem->next = elem;
	elem->prev = elem;
	if (nbr)
		elem->nbr = ft_atoi(nbr);
	a->size = 1;
}

int		ft_check_if_num(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (ft_isdigit(str[1]) != 1)
			return (ft_error());
		++i;
	}
	while (str[++i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (ft_error());
	}
	return (1);
}

int		ft_no_duplicate(t_head *head)
{
	t_stack	*tmp;

	tmp = head->beg;
	if (head->beg == head->end)
		return (1);
	if (tmp->nbr < INT_MIN || tmp->nbr > INT_MAX)
		return (ft_error());
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->nbr == tmp->prev->nbr
				|| tmp->nbr > INT_MAX || tmp->nbr < INT_MIN)
			return (ft_error());
		tmp = tmp->next;
		if (tmp == head->end)
			break;
	}
	return (1);
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

int		ft_set_stack(t_head **a, t_head **b, char **av)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = NULL;
	ft_init_head(a, b);
	while (av[++i])
	{
		tmp = ft_strsplit(av[i], ' ');
		if ((*a)->end ==  NULL)
		{
			ft_init_stack(*a, *tmp);
			++tmp;
		}
		while (*tmp)
		{
			if ((ft_check_if_num(*tmp)) == 0)
				return (0);
			if ((ft_add_stack(*a, *tmp)) == 0)
				return (0);
			++tmp;
		}
		//ft_strfree(*tmp); bug complet lololololol
	}
	if (ft_no_duplicate(*a) == 0)
		return (0);
	return (1);
}
