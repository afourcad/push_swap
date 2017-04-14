/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:33:00 by afourcad          #+#    #+#             */
/*   Updated: 2017/01/31 17:39:18 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flags(char **str, t_arg *param)
{
	param->param_good = TRUE;
	while (**str == '#' || **str == '0' || **str == '-' || **str == '+' ||
			**str == ' ')
	{
		if (**str == '#' && param->sharp != TRUE)
			param->sharp = TRUE;
		else if (**str == '0' && param->null != TRUE)
			param->null = TRUE;
		else if (**str == '-' && param->minus != TRUE)
			param->minus = TRUE;
		else if (**str == '+' && param->plus != TRUE)
			param->plus = TRUE;
		else if (**str == ' ' && param->space != TRUE)
			param->space = TRUE;
		else
			param_good = FALSE;
		++(*str);
	}
}

void	ft_check_width(char **str, t_arg *param)
{
	if (ft_isdigit(**str) == GOOD)
	{
		param->is_width = TRUE;
		param->width = ft_atoi(*str);
		while (ft_isdigit(**str) == GOOD)
			++(*str);
	}
	else
		param->is_width == FALSE;
}

void	ft_check_precision(char **str, t_arg *param)
{
	if (**str == '.' && ft_isdigit(**str + 1) == 1)
	{
		++(*str);
		param->precision = ft_atoi(*str);
		while (ft_isdigit(**str) == 1)
			++(*str);
		param->is_pre = TRUE;
	}
	else
		param->is_pre = FALSE;
}

void	ft_check_length(char **str, t_arg *param)
{
	if (**str == 'h' && **str + 1 == 'h')
	{
		param->len = hh;
		(*str) += 2;
	}
	else if (**str == 'l' && **str + 1 == 'l')
	{
		param->len = ll;
		(*str) += 2;
	}
	else if (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z')
	{
		if (**str == 'h')
			param->len = h;
		else if (**str == 'l')
			param->len = l;
		else if (**str == 'j')
			param->len = l;
		else if (**str == 'z')
			param->len = l;
		++(*str);
	}
	else
		param->len = none;
}
