/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:52:55 by afourcad          #+#    #+#             */
/*   Updated: 2017/03/27 15:53:09 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_free_param(t_arg *param)
{
	if (param == NULL)
		return ;
	ft_free_param(param->next);
	free(param);
}

void	ft_free_printf(char *buff, t_arg *param)
{
	free(buff);
	ft_free_param(param);
}
