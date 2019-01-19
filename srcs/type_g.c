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
	char		*val;
	long double	nbr;
	int			len;

	if (specs->size == L)
		nbr = va_arg(*ap, long double);
	else
		nbr = va_arg(*ap, double);
	specs->precision = PREC_F(specs->precision);
	len = ft_intlen(nbr);
	if (specs->precision >= len)
	{

		specs->precision = specs->precision - len;
		val = use_sval(specs, ft_dtoa(nbr, specs->precision));
	}
	else
	{
		if (specs->precision > 0)
			specs->precision--;
		val = use_sval(specs, ft_dtoa_e(nbr, specs->precision, specs));
	}
	print_value(specs, val, ft_strlen(val));
	free(val);
}
