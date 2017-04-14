/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_ln.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:41:12 by afourcad          #+#    #+#             */
/*   Updated: 2017/03/27 17:46:56 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_ln_string(va_list *ap, t_arg *param)
{
	int	ln;

	if (param->len == L)
		ln = ft_w_arg(ap, param, 0);
	else
	{
		if ((param->type.my_ptrchar = va_arg(*ap, char *)) == NULL)
			param->type.my_ptrchar = "(null)";
		ln = ft_strlen(param->type.my_ptrchar);
		if (param->is_pre == TRUE)
			ln = ln < param->precision ? ln : param->precision;
	}
	return (ln);
}

static int	ft_ln_char(va_list *ap, t_arg *param)
{
	int	ln;

	ln = 0;
	if (param->len == L)
		ln = ft_w_arg(ap, param, 0);
	else if (param->spec == PERCENT)
		++ln;
	else if (param->spec == WRONG)
	{
		param->type.my_char = param->specifier;
		++ln;
	}
	else
	{
		param->type.my_char = va_arg(*ap, int);
		++ln;
	}
	return (ln);
}

static int	ft_specific_case(char specifier, int ln, t_arg *param)
{
	ln = ln < param->precision ? param->precision : ln;
	if (param->precision == 0
			&& (((specifier == 'x' || specifier == 'X' || specifier == 'o'
			|| specifier == 'O' || specifier == 'u' || specifier == 'p')
			&& param->type.my_uint == 0)
			|| ((specifier == 'd' || specifier == 'i' || specifier == 'D')
			&& param->type.my_int == 0)))
		ln = 0;
	return (ln);
}

static int	ft_ln_digit(char specifier, va_list *ap, t_arg *param)
{
	int ln;

	if (specifier == 'd' || specifier == 'i')
		ln = ft_signed_decimal(ap, &(param->type.my_int), param->len, 10);
	else if (specifier == 'u')
		ln = ft_unsigned_decimal(ap, &(param->type.my_uint), param->len, 10);
	else if (specifier == 'x' || specifier == 'X')
		ln = ft_unsigned_decimal(ap, &(param->type.my_uint), param->len, 16);
	else if (specifier == 'o')
		ln = ft_unsigned_decimal(ap, &(param->type.my_uint), param->len, 8);
	else if (specifier == 'D')
		ln = ft_signed_decimal(ap, &(param->type.my_int), L, 10);
	else if (specifier == 'O')
		ln = ft_unsigned_decimal(ap, &(param->type.my_uint), L, 8);
	else if (specifier == 'p')
		ln = ft_unsigned_decimal(ap, &(param->type.my_uint), L, 16);
	else
		ln = ft_unsigned_decimal(ap, &(param->type.my_uint), L, 10);
	if (param->is_pre == TRUE)
		ln = ft_specific_case(specifier, ln, param);
	ln = ln + ft_ln_flags(specifier, param);
	return (ln);
}

int			ft_convert_size(va_list *ap, t_arg *param, int ln_tmp)
{
	int	ln;

	ln = 0;
	if (param->specifier == 's')
		ln = ft_ln_string(ap, param);
	else if (param->specifier == 'c' || param->specifier == '%'
			|| param->spec == WRONG)
		ln = ft_ln_char(ap, param);
	else if (param->specifier == 'd' || param->specifier == 'i'
			|| param->specifier == 'u' || param->specifier == 'o'
			|| param->specifier == 'x' || param->specifier == 'X'
			|| param->specifier == 'D' || param->specifier == 'O'
			|| param->specifier == 'U' || param->specifier == 'p')
		ln = ft_ln_digit(param->specifier, ap, param);
	else if (param->specifier == 'S' || param->specifier == 'C')
		ln = ft_w_arg(ap, param, 0);
	else if (param->specifier == 'b')
		ln = ft_signed_decimal(ap, &(param->type.my_int), LL, 2);
	if (ln == -1)
		return (-1);
	param->ln_block = ln;
	if (param->is_width == TRUE && ln >= 0)
		ln = ln < param->width ? param->width : ln;
	return (ln + ln_tmp);
}
