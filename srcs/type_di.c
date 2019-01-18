/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 15:16:30 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/10 15:16:36 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type_di(f_specs *specs, va_list *ap)
{
	int			sign;
	long long	nbr;
	char		*val;
	int			len;

	sign = 0;
	nbr = va_arg(*ap, long long);
	if (specs->size == hh)	
		val = use_sval(specs, re_val(ft_itoa_base((char)nbr, 10), &sign), sign);	
	else if (specs->size == h)
		val = use_sval(specs, re_val(ft_itoa_base((short int)nbr, 10), &sign), sign);	
	else if (specs->size == l)
		val = use_sval(specs, re_val(ft_itoa_base((long)nbr, 10), &sign), sign);
	else if (specs->size == ll)
		val = use_sval(specs, re_val(ft_itoa_base((long long)nbr, 10), &sign), sign);
	else if (specs->size == j)
		val = use_sval(specs, re_val(ft_itoa_base((intmax_t)nbr, 10), &sign), sign);
	else if (specs->size == z)
		val = use_sval(specs, re_val(ft_itoa_base((size_t)nbr, 10), &sign), sign);
	else if (specs->size == t)
		val = use_sval(specs, re_val(ft_itoa_base((intptr_t)nbr, 10), &sign), sign);
	else
		use_sval(specs, re_val(ft_itoa_base((int)nbr, 10), &sign), sign);
	len = ft_strlen(val);
	print_value(specs, val, len);
}
