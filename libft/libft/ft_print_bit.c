/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:19:40 by afourcad          #+#    #+#             */
/*   Updated: 2017/03/07 18:19:42 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_octet(int nb)
{
	int	bit;
	int	mask;
	int	i;

	i = 7;
	mask = 128;
	while (i >= 0)
	{
		bit = (nb & mask) >> i;
		ft_putnbr(bit);
		mask >>= 1;
		i--;
	}
	ft_putchar('\n');
}

void	ft_print_bit(int nb)
{
	ft_print_octet(nb);
	if (nb > 0x007f && nb <= 0xfffff)
	{
		ft_print_octet(nb >> 8);
		if (nb > 0x07ff && nb <= 0xfffff)
		{
			ft_print_octet(nb >> 16);
			if (nb > 0xffff && nb < 0xfffff)
				ft_print_octet(nb >> 24);
		}
	}
	ft_putchar('\n');
}
