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

void	print_type_percent(f_specs *specs, t_value *value)
{
	char *val;
	char *tmp_str;

	val = ft_strnew(1);
	value->c_val = '%';
	val[0] = value->c_val;
	if(specs->flags[flag_zero] && !specs->flags[flag_minus])
	{
		tmp_str = ft_strnew(specs->width - 1);
		ft_memset(tmp_str, '0', specs->width - 1);
		val = ft_strjoin(tmp_str, val);
		free(tmp_str);
	}
	else
		specs->flags[flag_zero] = 0;
	print_value(specs, val, ft_strlen(val));
}
