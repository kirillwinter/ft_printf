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

	sign = 0;
	nbr = va_arg(*ap, long long);
	if (specs->size == hh)	
		use_val_difF(specs, re_val(ft_itoa_base((char)nbr, 10), &sign), sign);	
	else if (specs->size == h)
		use_val_difF(specs, re_val(ft_itoa_base((short int)nbr, 10), &sign), sign);	
	else if (specs->size == l)
		use_val_difF(specs, re_val(ft_itoa_base((long)nbr, 10), &sign), sign);
	else if (specs->size == ll)
		use_val_difF(specs, re_val(ft_itoa_base((long long)nbr, 10), &sign), sign);
	else
		use_val_difF(specs, re_val(ft_itoa_base((int)nbr, 10), &sign), sign);
}
