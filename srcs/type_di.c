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

void	print_type_di(f_specs *specs, t_value *value, va_list *ap)
{
	char *val;
	int len;
	
	len = 0;
	if (specs->size == 0 || specs->size == hh || specs->size == h)	
	{
		value->i_val = va_arg(*ap, int);
		val = ft_itoa(value->i_val);
		len = ft_strlen(val);
		// printf("len = %d\n", len);
		while (specs->width > len)
		{
			ft_putchar(' ');
			len++;
		}
		ft_putstr(val);
	}
	else if (specs->size == l)
	{
		value->l_val = va_arg(*ap, long);
		ft_putstr(ft_itoa((int)value->l_val));
	}
	else if (specs->size == ll)
		value->ll_val = va_arg(*ap, long long int);
	else if (specs->size == L)
		value->L_val = va_arg(*ap, int64_t);
}