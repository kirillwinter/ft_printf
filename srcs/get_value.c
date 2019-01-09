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
	if (specs->type == 'd' && specs->size == 0)	
		value->i_val = va_arg(*ap, int);
	else if (specs->type == 'd' && specs->size == l)
		value->l_val = va_arg(*ap, long);
	printf("val = %ld\n", value->l_val);
}
