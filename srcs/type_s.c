/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:34:18 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/10 15:34:19 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

void	print_type_s(f_specs *specs, t_value *value, va_list *ap)
{
	char *val;
	int len;

	value->s_val = va_arg(*ap, char *);
	if (!specs->precision)
		val = value->s_val;
	else
	{
		val = ft_strnew(specs->precision);
		val = ft_strncat(val, value->s_val, specs->precision);
	}
	len = ft_strlen(val);
	specs->flags[flag_zero] = 0;
	print_value(specs, val, len);
}
