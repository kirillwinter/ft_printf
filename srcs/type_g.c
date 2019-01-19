/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:56:25 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/17 20:56:28 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_type_g(f_specs *specs, va_list *ap)
{
	char	*val;
	int		sign;

	sign = 0;
	// if (specs->precision > ft_intlen())
	if (specs->precision > 1)
		specs->precision -= 1;
	// print_type_e(specs, ap);
	print_type_f(specs, ap);
	// if (specs->size == L)
	// 	val = use_sval(specs, ft_dtoa(va_arg(*ap,long double), specs->precision));
	// else
	// 	val = use_sval(specs, ft_dtoa(va_arg(*ap, double), specs->precision));
	// print_value(specs, val, ft_strlen(val));
	// free(val);
}
