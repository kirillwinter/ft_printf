/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:34:11 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/10 15:34:13 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type_c(f_specs *specs, va_list *ap)
{
	char *val;
	char *tmp_str;

	val = ft_strnew(1);
	val[0] = va_arg(*ap, int);
	if (specs->flags[flag_zero] && !specs->flags[flag_minus])
	{
		tmp_str = ft_strnew(specs->width - 1);
		ft_memset(tmp_str, '0', specs->width - 1);
		val = ft_strjoin(tmp_str, val);
		free(tmp_str);
	}
	else if (specs->flags[flag_zero] && specs->flags[flag_minus])
		specs->flags[flag_zero] = 0;
	print_value(specs, val, 1);
	free(val);
}
