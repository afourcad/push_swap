/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:19:45 by afourcad          #+#    #+#             */
/*   Updated: 2017/03/06 16:24:40 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_write_dec_plus(char *buff, int is_neg)
{
	*buff = is_neg == TRUE ? '-' : '+';
	++buff;
	return (buff);
}

char	*ft_write_dec_space(char *buff)
{
	*buff = ' ';
	++buff;
	return (buff);
}
