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

void	print_type_c(f_specs *specs, t_value *value, va_list *ap)
{
	if (specs->flags == 0)
		specs->flags = 0;
	value->c_val = va_arg(*ap, int);
	ft_putchar(value->c_val);
}
