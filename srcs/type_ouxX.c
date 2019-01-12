/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ouxX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:03:03 by jwillem-          #+#    #+#             */
/*   Updated: 2019/01/12 15:03:06 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type_ouxX(f_specs *specs, t_value *value, va_list *ap)
{
	char	*res;

	if (specs->flags[flag_zero] == 0)
		specs->flags[flag_zero] = 0;
	value->ouxX_val = va_arg(*ap, unsigned long long);
	if (specs->type == 'o')
		res = ft_uitoa_base(value->ouxX_val, 8, specs->type);
	else if (specs->type == 'u')
		res = ft_uitoa_base(value->ouxX_val, 10, specs->type);
	else //if (specs->type == 'x' || specs->type == 'X')
		res = ft_uitoa_base(value->ouxX_val, 16, specs->type);
	ft_putstr(res);
	free(res);
}
