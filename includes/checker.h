/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:40:07 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/16 16:15:06 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define HEAD a

typedef struct	s_stack
{
	long			nbr;
	int				grp;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

typedef	struct	s_head
{
	t_stack	*beg;
	t_stack	*end;
	int		size;
}				t_head;

typedef struct	s_tab
{
	int	*tab;
	int	size;
	int	grp;
	int	rra;
}				t_tab;

int				ft_set_stack(t_head **a, t_head **b, char **av);
int				ft_set_tab(t_head *head, t_tab *tab);
int				ft_add_stack(t_head *head, char *str);
int				ft_no_duplicate(t_head *head);
int				ft_check_if_num(char *str);

void			ft_sort_b(t_head *a, t_head *b, int *size, char *flags);
void			ft_small_size(t_head *a, t_head *b, int *size, char *flags);

void			ft_swap(t_head *lst1, t_head *lst2, char *str, int i);
void			ft_push(t_head *lst1, t_head *lst2, char *str, int i);
void			ft_rotate(t_head *lst1, t_head *lst2, char *str, int i);
void			ft_r_rotate(t_head *lst1, t_head *lst2, char *str, int i);
int				ft_do_opperations(t_head *a, t_head *b, char *tab, int i);
int				ft_only_pa(t_head *a, t_head *b, char *flags);

void			ft_init_head(t_head **a, t_head **b);
int				ft_error(void);
int				ft_is_partial_sort(t_head *a, t_head *b, char *flags);
int				ft_is_sort(t_head *a, t_head *b);
char			*ft_find_flags(char *str);

int				ft_free_op(t_head **a, t_head **b);
int				ft_free_all(t_head **a, t_head **b, char ***tmp);

void			ft_afficher(t_head *a, t_head *b, char *flags);

int				ft_find_operations(t_head *a, t_head *b, char *flags);
int				ft_find_operations2(t_head *a, t_head *b, char *flags);
int				ft_algo3(t_head *a, t_head *b, char *flags);
void			ft_algo3_b(t_head *a, t_head *b, char *flags);
int				ft_size_grp(t_head *head, t_tab *tab);
int				ft_write_sort(int i);

#endif
