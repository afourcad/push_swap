/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:08:13 by afourcad          #+#    #+#             */
/*   Updated: 2017/02/21 15:57:56 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_utf8_len(uintmax_t nbr)
{
	if (MB_CUR_MAX == 1)
	{
		if (nbr <= 255)
			return (1);
		else
			return (-1);
	}
	if ((nbr >= 0xd800 && nbr <= 0xdfff)
			|| (nbr >= 0x110000 && nbr <= 0x1fffff))
		return (-1);
	if (nbr <= 0x7f)
		return (1);
	else if (nbr > 0x7f && nbr <= 0xfff)
		return (2);
	else if (nbr > 0xfff && nbr <= 0xffff)
		return (3);
	else if (nbr > 0xffff && nbr <= 0x1fffff)
		return (4);
	else
		return (-1);
}
