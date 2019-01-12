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
	else if (type == 's')
		print_type_s(specs, value, ap);
	else if (type == 'o' || type == 'u' || type == 'x'|| type == 'X')
		print_type_ouxX(specs, value, ap);
	else if (type == '%')
		print_type_percent(specs, value);
}

void	print_value(f_specs *specs, char *val, int len_val)
{
	g_len += len_val;
	if (!specs->flags[flag_zero])
	{
		if (specs->flags[flag_minus])
		{
			ft_putstr(val);
			while (specs->width > len_val++)
			{
				ft_putchar(' ');
				g_len++;
			}
		}
		else
		{
			while (specs->width > len_val++)
			{
				ft_putchar(' ');
				g_len++;
			}
			ft_putstr(val);
		}
	}
	else
		ft_putstr(val);
	free(val);
}
