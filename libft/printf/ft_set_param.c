/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:58:08 by afourcad          #+#    #+#             */
/*   Updated: 2017/03/27 17:47:34 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_param(t_arg *param)
{
	param->param_good = FALSE;
	param->sharp = FALSE;
	param->null = FALSE;
	param->minus = FALSE;
	param->plus = FALSE;
	param->space = FALSE;
	param->param_good = FALSE;
	param->sharp = FALSE;
	param->is_width = FALSE;
	param->width = 0;
	param->is_pre = FALSE;
	param->precision = 0;
	param->ln_block = 0;
	param->nbr_utf8_char = 0;
	param->len = NONE;
	param->is_spec = FALSE;
	param->spec = NOP;
	param->specifier = 0;
}
