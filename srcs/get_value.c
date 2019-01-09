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
	if (specs->type == 'd' || specs->type == 'i')
	{
		if (specs->size == 0 || specs->size == hh || specs->size == h)	
		{
			value->i_val = va_arg(*ap, int);
			ft_putstr(ft_itoa(value->i_val));
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
	
	// ft_putnbr((int)value->l_val);
}