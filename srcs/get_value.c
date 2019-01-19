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

void	get_value(f_specs *specs, va_list *ap)
{
	char	type;

	type = specs->type;
	if (type == 'd')
		print_type_di(specs, ap);
	else if (type == 'c')
		print_type_c(specs, ap);
	else if (type == 'p')
		print_type_p(specs, ap);
	else if (type == 's')
		print_type_s(specs, ap);
	else if (type == 'o' || type == 'u' || type == 'x' 
		|| type == 'X' || type == 'b')
		print_type_oux(specs, ap);
	else if (type == '%')
		print_type_percent(specs);
	else if (type == 'f' || type == 'F')
		print_type_f(specs, ap);
	else if (type == 'e' || type == 'E')
		print_type_e(specs, ap);
	else if (type == 'a' || type == 'A')
		print_type_a(specs, ap);
	else if (type == 'g' || type == 'G')
		print_type_g(specs, ap);
}

void	print_value(f_specs *specs, char *val, int len_val)
{
	char *tmp_str;
	
	if (!specs->flags[flag_zero] && specs->width > len_val)
	{
		tmp_str = ft_strnew(specs->width - len_val);
		ft_memset(tmp_str, ' ', specs->width - len_val);
		if (specs->flags[flag_minus])
			val = ft_strjoin_free(val, tmp_str, 3);
		else
			val = ft_strjoin_free(tmp_str, val, 3);
		g_len += specs->width;
		// free(tmp_str);
		write(1, val, specs->width);
		return ;
	}
	else
		write(1, val, len_val);
	g_len += len_val;
}
