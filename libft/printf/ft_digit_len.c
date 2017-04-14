/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:48:12 by afourcad          #+#    #+#             */
/*   Updated: 2017/03/27 17:45:43 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_ln_flags(char specifier, t_arg *param)
{
	int	ln;

	ln = 0;
	if (specifier == 'p' || (param->sharp == TRUE &&
			(specifier == 'x' || specifier == 'X')
			&& param->type.my_uint != 0))
		ln += 2;
	if (param->sharp == TRUE && (specifier == 'o' || specifier == 'O')
				&& ((param->is_pre != TRUE && param->type.my_uint != 0)
				|| (param->is_pre == TRUE
				&& (((ft_base_digitlen(param->type.my_uint, 8)
				>= param->precision))
				|| param->precision == 0))))
		++ln;
	if ((specifier == 'd' || specifier == 'i' || specifier == 'D')
			&& ((param->plus == TRUE || param->type.my_int < 0)
			|| (param->space == TRUE && param->type.my_int >= 0)))
		++ln;
	return (ln);
}

int	ft_w_arg(va_list *ap, t_arg *param, int ln_tmp)
{
	int		ln;
	int		i;
	wchar_t	*s;

	ln = 0;
	i = 0;
	s = NULL;
	if (param->specifier == 'c' || param->specifier == 'C')
		return (ft_utf8_len(param->type.my_wint_t = va_arg(*ap, wint_t)));
	else if (param->specifier == 's' || param->specifier == 'S')
	{
		if ((param->type.my_wchar_t = va_arg(*ap, wchar_t *)) == NULL)
			param->type.my_wchar_t = L"(null)";
		s = param->type.my_wchar_t;
		while (s[i] && ln >= 0)
		{
			if (param->is_pre == TRUE
					&& (ln_tmp = (ln + ft_utf8_len(s[i]))) > param->precision)
				return (ln);
			else
				ln = ft_utf8_len(s[i]) ? (ln + ft_utf8_len(s[i])) : -1;
			param->nbr_utf8_char = ++i;
		}
	}
	return (ln);
}

int	ft_signed_decimal(va_list *ap, intmax_t *my_int, t_length len,
		int base)
{
	if (len == NONE)
		*my_int = (intmax_t)va_arg(*ap, int);
	else if (len == HH)
		*my_int = (signed char)va_arg(*ap, int);
	else if (len == H)
		*my_int = (short int)va_arg(*ap, int);
	else if (len == L)
		*my_int = (intmax_t)va_arg(*ap, long);
	else if (len == LL)
		*my_int = (intmax_t)va_arg(*ap, long long);
	else if (len == J)
		*my_int = (intmax_t)va_arg(*ap, intmax_t);
	else if (len == Z)
		*my_int = (intmax_t)va_arg(*ap, size_t);
	return (ft_base_digitlen(ft_abs(*my_int), base));
}

int	ft_unsigned_decimal(va_list *ap, uintmax_t *my_uint,
		t_length len, int base)
{
	if (len == NONE)
		*my_uint = (uintmax_t)va_arg(*ap, unsigned int);
	else if (len == HH)
		*my_uint = (unsigned char)va_arg(*ap, unsigned int);
	else if (len == H)
		*my_uint = (unsigned short int)va_arg(*ap, unsigned int);
	else if (len == L)
		*my_uint = (uintmax_t)va_arg(*ap, unsigned long);
	else if (len == LL)
		*my_uint = (uintmax_t)va_arg(*ap, unsigned long long);
	else if (len == J)
		*my_uint = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (len == Z)
		*my_uint = (uintmax_t)va_arg(*ap, size_t);
	return (ft_base_digitlen(*my_uint, base));
}
