/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:40:07 by afourcad          #+#    #+#             */
/*   Updated: 2017/04/21 19:19:02 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H

# define HEAD a

typedef struct	s_stack
{
	long			nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

typedef	struct	s_head
{
	t_stack	*beg;
	t_stack	*end;
	int		size;
}				t_head;

int		ft_set_stack(t_head **a, t_head **b, char **av);
int		ft_add_stack(t_head *head, char *str);
void	ft_swap(t_head *lst1, t_head *lst2, char *str, int i);
void	ft_push(t_head *lst1, t_head *lst2, char *str, int i);
void	ft_rotate(t_head *lst1, t_head *lst2, char *str, int i);
void	ft_r_rotate(t_head *lst1, t_head *lst2, char *str, int i);
int		ft_do_opperations(t_head *a, t_head *b, char *tab, int i);
int		ft_error(void);
int		ft_is_partial_sort(t_head *a, t_head *b, char *flags);
int		ft_is_sort(t_head *a, t_head *b);
char	*ft_find_flags(char *str);
void	ft_free_op(t_head **a, t_head **b);
void	ft_afficher(t_head *a, t_head *b);
int		ft_find_operations(t_head *a, t_head *b, char *flags);
int		ft_find_operations2(t_head *a, t_head *b, char *flags);
int		ft_write_sort(int i);
int		ft_only_pa(t_head *a, t_head *b, char *flags);

#endif
