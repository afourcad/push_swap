/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_width_pre.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:05:28 by afourcad          #+#    #+#             */
/*   Updated: 2017/03/27 17:30:29 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_width_and_pre(char *buff, t_arg *param, char *nbr, int neg)
{
	char	c;

	c = param->specifier;
	if (param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, ' ');
	if ((c == 'd' || c == 'i' || c == 'D')
			&& (param->plus == TRUE || neg == TRUE))
		buff = ft_write_dec_plus(buff, neg);
	else if ((c == 'd' || c == 'i' || c == 'D')
			&& (param->space == TRUE && neg == FALSE))
		buff = ft_write_dec_space(buff);
	else if ((((c == 'x' || c == 'X') && param->sharp == TRUE) || c == 'p')
			&& (param->type.my_uint != 0 || param->precision != 0))
		buff = c == 'X' ? ft_memcpy(buff, "0X", 2) : ft_memcpy(buff, "0x", 2);
	else if ((c == 'o' || c == 'O') && param->sharp == TRUE
			&& (param->type.my_uint != 0 || param->precision == 0))
		buff = ft_memcpy(buff, "0", 1);
	if ((size_t)param->precision > ft_strlen(nbr))
		buff = ft_bzerocustom(buff, param->precision - ft_strlen(nbr), '0');
	else if (param->width <= param->ln_block
			&& ft_strlen(nbr) < (size_t)param->precision)
		buff = ft_bzerocustom(buff, param->precision - ft_strlen(nbr), '0');
	if (param->precision == 0 && param->type.my_int == 0)
		return (buff);
	return (ft_memcpy(buff, nbr, ft_strlen(nbr)));
}

char	*ft_only_width(char *buff, t_arg *param, char *nbr, int neg)
{
	char	c;

	c = param->specifier;
	if (param->width > param->ln_block && (param->null != TRUE
			|| param->space == TRUE))
		buff = ft_bzerocustom(buff, param->width - param->ln_block, ' ');
	if ((c == 'd' || c == 'i' || c == 'D')
			&& (param->plus == TRUE || neg == TRUE))
		buff = ft_write_dec_plus(buff, neg);
	else if ((c == 'd' || c == 'i' || c == 'D')
			&& (param->space == TRUE && neg == FALSE
			&& param->width <= param->ln_block))
		buff = ft_write_dec_space(buff);
	else if ((((c == 'x' || c == 'X') && param->sharp == TRUE)
			&& param->type.my_uint != 0) || c == 'p')
		buff = c == 'X' ? ft_memcpy(buff, "0X", 2) : ft_memcpy(buff, "0x", 2);
	else if ((c == 'o' || c == 'O') && param->sharp == TRUE
			&& param->type.my_uint != 0)
		buff = ft_memcpy(buff, "0", 1);
	if (param->null == TRUE && param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, '0');
	buff = ft_memcpy(buff, nbr, ft_strlen(nbr));
	return (buff);
}

char	*ft_only_pre(char *buff, t_arg *param, char *nbr, int neg)
{
	char	c;

	c = param->specifier;
	if ((c == 'd' || c == 'i' || c == 'D')
			&& (param->plus == TRUE || neg == TRUE))
		buff = ft_write_dec_plus(buff, neg);
	else if ((c == 'd' || c == 'i' || c == 'D')
			&& (param->space == TRUE && neg == FALSE))
		buff = ft_write_dec_space(buff);
	else if (c == 'p' || (((c == 'x' || c == 'X') && param->sharp == TRUE)
			&& (param->type.my_uint != 0 || param->precision != 0)))
		buff = c == 'X' ? ft_memcpy(buff, "0X", 2) : ft_memcpy(buff, "0x", 2);
	else if ((c == 'o' || c == 'O') && param->sharp == TRUE
			&& param->precision == 0)
		buff = ft_memcpy(buff, "0", 1);
	if (ft_strlen(nbr) < (size_t)param->precision)
		buff = ft_bzerocustom(buff, param->precision - ft_strlen(nbr), '0');
	if (param->precision == 0 && param->type.my_int == 0
			&& (c != 'o' || c != 'O'))
		return (buff);
	return (ft_memcpy(buff, nbr, ft_strlen(nbr)));
}

char	*ft_no_pre_no_width(char *buff, t_arg *param, char *nbr, int neg)
{
	char	c;

	c = param->specifier;
	if ((c == 'd' || c == 'i' || c == 'D')
			&& (param->plus == TRUE || neg == TRUE))
		buff = ft_write_dec_plus(buff, neg);
	else if ((c == 'd' || c == 'i' || c == 'D')
			&& (param->space == TRUE && neg == FALSE))
		buff = ft_write_dec_space(buff);
	else if (((c == 'x' || c == 'X') && param->sharp == TRUE
			&& param->type.my_uint != 0) || c == 'p')
		buff = c == 'X' ? ft_memcpy(buff, "0X", 2) : ft_memcpy(buff, "0x", 2);
	else if ((c == 'o' || c == 'O') && param->sharp == TRUE
			&& param->type.my_uint != 0)
		buff = ft_memcpy(buff, "0", 1);
	buff = ft_memcpy(buff, nbr, ft_strlen(nbr));
	return (buff);
}
