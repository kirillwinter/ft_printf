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


	if (specs->size == l)
	{
		// val = (wchar_t *)val;
		val = ft_strdup(va_arg(*ap, char *));
	}
	else
		val = ft_strdup(va_arg(*ap, char *));
	if (val == NULL)
		val = "(null)"; 
	if (specs->precision >= 0)
	{
		tmp_str = ft_strnew(specs->precision);
		val = ft_strncat(tmp_str, val, specs->precision);
		// free(tmp_str);
	}
	len = ft_strlen(val);
	if (specs->flags[flag_zero] && !specs->flags[flag_minus])
		val = filling_zero(val, specs->width - len);
	else if (specs->flags[flag_zero] && specs->flags[flag_minus])
		specs->flags[flag_zero] = 0;
	len = ft_strlen(val);
	print_value(specs, val, len);
}
