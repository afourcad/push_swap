/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str_width_pre.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:55:32 by afourcad          #+#    #+#             */
/*   Updated: 2017/03/27 17:40:15 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_write_char_with_flags(char *buff, t_arg *param)
{
	if ((param->specifier == '%' || param->specifier == 'c'
				|| param->spec == WRONG) && param->minus == TRUE)
		*buff++ = param->specifier == '%' ? '%' : param->type.my_char;
	if (param->is_width == TRUE
			&& param->null == TRUE && param->minus != TRUE
			&& param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, '0');
	else if (param->is_width == TRUE && param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, ' ');
	if ((param->specifier == '%' || param->specifier == 'c'
				|| param->spec == WRONG) && param->minus != TRUE)
		*buff++ = param->specifier == '%' ? '%' : param->type.my_char;
	return (buff);
}

char	*ft_write_str_with_flags(char *buff, t_arg *param, int ln_str)
{
	if (param->minus == TRUE)
		buff = ft_memcpy(buff, param->type.my_ptrchar, ln_str);
	if (param->is_width == TRUE
			&& param->null == TRUE && param->minus != TRUE
			&& param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, '0');
	else if (param->is_width == TRUE && param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, ' ');
	if (param->minus != TRUE)
		buff = ft_memcpy(buff, param->type.my_ptrchar, ln_str);
	return (buff);
}

char	*ft_write_unicode_with_flags(char *buff, t_arg *param)
{
	if (param->null == TRUE && param->minus != TRUE
			&& param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, '0');
	else if (param->is_width && param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, ' ');
	return (buff);
}
