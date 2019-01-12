/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:24:05 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/09 17:24:07 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

void	get_value(f_specs *specs, t_value *value, va_list *ap)
{
	char	type;

	type = specs->type;	
	if (type == 'd' || type == 'i')
		print_type_di(specs, value, ap);
	else if (type == 'c')
		print_type_c(specs, value, ap);
	else if (type == 'p')
		print_type_p(specs, value, ap);
	else if (type == 'o' || type == 'u' || type == 'x'|| type == 'X')
		print_type_ouxX(specs, value, ap);
	else if (type == '%')
		ft_putchar('%');
	
	// ft_putnbr((int)value->l_val);
}