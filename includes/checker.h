/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:40:07 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/14 18:49:10 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H

# define HEAD "head"

typedef struct	s_op
{
	char		*str;
	struct s_op	*next;
}				t_op;

typedef struct	s_stack
{
	char			*nbr;
	struct s_stack	*next;
}				t_stack;

void	ft_set_stack(t_stack **a, t_stack **b, int ac, char **av);
void	ft_add_op(t_stack **op, char *str);

#endif
