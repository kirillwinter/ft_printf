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
	if (specs->flags[flag_zero] == 0)
		specs->flags[flag_zero] = 0;
	value->s_val = va_arg(*ap, char *);
	ft_putstr(value->s_val);
}
