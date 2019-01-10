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

void	flag_minus_handling(f_specs *specs, int len_val, char *val)
{
	if (specs->flags[flag_minus] != 0)
	{
		ft_putstr(val);
		while (specs->width > len_val)
		{
			ft_putchar(' ');
			len_val++;
		}
	}
	else
	{
		while (specs->width > len_val)
		{
			ft_putchar(' ');
			len_val++;
		}
		ft_putstr(val);
	}
}

// void	flag_zero_handling(f_specs *specs, int len_val, char *val)
// {
// 	ft_putstr(val);
// 	// if (specs->flags[flag_minus] != 0)
// 	// {
// 	// 	ft_putstr(val);
// 	// 	while (specs->width > len_val)
// 	// 	{
// 	// 		ft_putchar('0');
// 	// 		len_val++;
// 	// 	}
// 	// }
// 	// else
// 	// {
// 	// 	while (specs->width > len_val)
// 	// 	{
// 	// 		ft_putchar('0');
// 	// 		len_val++;
// 	// 	}
// 	// 	ft_putstr(val);
// 	// }
// }

void	print_type_di(f_specs *specs, t_value *value, va_list *ap)
{
	char *val;
	int len_val;
	char *ret_str;
	
	len_val = 0;
	if (specs->size == 0 || specs->size == hh || specs->size == h)	
	{
		value->i_val = va_arg(*ap, int);
		val = ft_itoa(value->i_val);
		len_val = ft_strlen(val);
		if (specs->flags[flag_zero] && !specs->precision && specs->width > len_val && value->i_val >= 0)
		{
			ret_str = ft_strnew(specs->width - len_val);
			ft_memset(ret_str, '0', specs->width - len_val);
			val = ft_itoa(ABS(value->i_val));
			val = ft_strjoin(ret_str, val);
			val[0] = '+';
		}
		else if (specs->flags[flag_zero] && !specs->precision && specs->width > len_val && value->i_val < 0)
		{
			ret_str = ft_strnew(specs->width - len_val + 1);
			ft_memset(ret_str, '0', specs->width - len_val + 1);
			val = ft_itoa(ABS(value->i_val));
			val = ft_strjoin(ret_str, val);
			val[0] = '-';
		}
		if (specs->flags[flag_plus] && value->i_val > 0 && !specs->flags[flag_zero]) // обработка флага +
		{
			val = ft_strjoin("+", val);
			len_val++;
		}
		else if (!specs->flags[flag_plus] && value->i_val > 0 && specs->flags[flag_space]) // обработка флага ' '
		{
			val = ft_strjoin(" ", val);
			len_val++;
		}
		if (!specs->flags[flag_zero])
			flag_minus_handling(specs, len_val, val); // обработка флага - 
		else
			ft_putstr(val);
			// flag_zero_handling(specs, len_val, val);
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