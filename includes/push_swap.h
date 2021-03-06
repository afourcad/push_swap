/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 16:29:57 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/15 18:24:11 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FLG_V flags[0]
# define FLG_C flags[1]

# define A1 a->beg->nbr
# define B1 a->beg->next->nbr
# define C1 a->beg->next->next->nbr
# define Z1 a->end->nbr
# define A2 b->beg->nbr
# define B2 b->beg->next->nbr
# define C2 b->beg->next->next->nbr
# define Z2 b->end->nbr

typedef struct	s_min
{
	int	min;
	int	next;
	int	is_min;
	int is_next;
}				t_min;

#endif
