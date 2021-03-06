/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:03:42 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/16 16:04:00 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uintmax_t	ft_abs(intmax_t nbr)
{
	if (nbr < 0)
		nbr = nbr * -1;
	return (nbr);
}
