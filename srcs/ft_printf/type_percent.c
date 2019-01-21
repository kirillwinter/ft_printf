/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 22:40:36 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/12 22:40:37 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

void	print_type_percent(f_specs *specs)
{
	char *val;

	val = ft_strnew(1);
	val[0] = '%';
	if (specs->flags[flag_zero] && !specs->flags[flag_minus] && specs->width > 1)
		val = filling_zero(val, specs->width - 1);
	// else if (specs->flags[flag_zero] && specs->flags[flag_minus])
	// 	specs->flags[flag_zero] = 0;
	print_value(specs, val, ft_strlen(val));
	// free(val);
}
