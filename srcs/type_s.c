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

void	print_type_s(f_specs *specs, va_list *ap)
{
	char	*val;
	char	*tmp_str;
	int		len;

	val = va_arg(*ap, char *);
	if (specs->precision)
	{
		tmp_str = ft_strnew(specs->precision);
		val = ft_strncat(tmp_str, val, specs->precision);
	}
	len = ft_strlen(val);
	if (specs->flags[flag_zero] && !specs->flags[flag_minus])
	{
		tmp_str = ft_strnew(specs->width - len);
		ft_memset(tmp_str, '0', specs->width - len);
		val = ft_strjoin(tmp_str, val);
	}
	else if (specs->flags[flag_zero] && specs->flags[flag_minus])
		specs->flags[flag_zero] = 0;
	len = ft_strlen(val);
	print_value(specs, val, len);
	free(tmp_str);
}
