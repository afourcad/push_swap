/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_sdigitlen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:06:26 by afourcad          #+#    #+#             */
/*   Updated: 2017/03/03 18:15:54 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_base_digitlen(uintmax_t nbr, int base)
{
	int	ln;

	ln = 0;
	if (nbr == 0)
		ln = 1;
	while (nbr != 0)
	{
		nbr = nbr / base;
		++ln;
	}
	return (ln);
}
