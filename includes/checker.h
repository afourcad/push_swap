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

typedef struct	s_stack
{
	char			*nbr;
	struct s_stack	*next;
}				t_stack;

int		ft_set_stack(t_stack **a, char **av);
int		ft_add_stack(t_stack **op, char *str);
void	ft_swap(t_stack **lst1, t_stack **lst2);
void	ft_push(t_stack **lst1, t_stack **lst2);
void	ft_rotate(t_stack **lst1, t_stack **lst2);
void	ft_r_rotate(t_stack **lst1, t_stack **lst2);
int		ft_do_opperations(t_stack **a, t_stack **b, char *tab);
int		ft_error(void);
int		ft_is_sort(t_stack *a, t_stack *b);

#endif
