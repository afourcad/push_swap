/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:16:24 by afourcad          #+#    #+#             */
/*   Updated: 2017/03/27 17:36:53 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_find_specifier(char **str, t_arg *param)
{
	if (**str == 's' || **str == 'S' || **str == 'p' || **str == 'd'
			|| **str == 'D' || **str == 'i' || **str == 'o' || **str == 'O'
			|| **str == 'u' || **str == 'U' || **str == 'x' || **str == 'b'
			|| **str == 'X' || **str == 'C' || **str == 'c')
		param->spec = YES;
	else if (**str == '%')
		param->spec = PERCENT;
	else
		param->spec = WRONG;
	param->specifier = **str;
	return (param->spec);
}
