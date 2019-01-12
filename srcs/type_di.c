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
}

char	*handling_precision(f_specs *specs, int sign, char *val, int len_val)
{
	char *tmp_str;

	specs->flags[flag_zero] = 0;
	if (sign < 0)
		len_val--;
	tmp_str = ft_strnew(specs->precision - len_val);
	ft_memset(tmp_str, '0', specs->precision - len_val);
	val = ft_strjoin(tmp_str, val);
	if (sign < 0)
		val = ft_strjoin("-", val);
	return (val);
}


char	*handling_zero_flag(f_specs *specs, int sign, char *val, int len_val)
{
	char *tmp_str;

	tmp_str = ft_strnew(specs->width - len_val);
	ft_memset(tmp_str, '0', specs->width - len_val);
	val = ft_strjoin(tmp_str, val);
	if (sign < 0)
		val = ft_strjoin("-", val);
	if (specs->flags[flag_plus] && sign >= 0)
		val[0] = '+';
	else if (specs->flags[flag_space] && val[0] != '-')
		val[0] = ' ';
	return (val);
}

void	use_val(f_specs *specs, char *val, int sign)
{
	int len_val;
		
	len_val = ft_strlen(val);
	if (sign < 0)
		len_val++;
	if (specs->precision && specs->precision > len_val) // берем значение если точность существует
		val = handling_precision(specs, sign, val, len_val);
	else if (specs->flags[flag_zero] && specs->width > len_val) // обработка флага 0
		val = handling_zero_flag(specs, sign, val, len_val);
	else if (sign < 0)
		val = ft_strjoin("-", val);
	else if (specs->flags[flag_plus] && sign >= 0) // обработка флага +
		val = ft_strjoin("+", val);
	else if (!specs->flags[flag_plus] && sign >= 0 && specs->flags[flag_space]) // обработка флага ' '
		val = ft_strjoin(" ", val);
	len_val = ft_strlen(val);
	print_value(specs, val, len_val); // обработка флага - или вывод всех значений кроме флага 0
}

void	print_type_di(f_specs *specs, t_value *value, va_list *ap)
{
	int	sign;

	sign = 0;
	if (specs->size == 0 || specs->size == hh || specs->size == h)	
	{
		if ((value->i_val = va_arg(*ap, int)) < 0)
			sign = -1;
		use_val(specs, ft_uitoa_base(ABS(value->i_val), 10, specs->type), sign);
	}
	else if (specs->size == l)
	{
		if ((value->l_val = va_arg(*ap, int)) < 0)
			sign = -1;
		use_val(specs, ft_uitoa_base(ABS(value->l_val), 10, specs->type), sign);
	}
	else if (specs->size == ll)
	{
		if ((value->ll_val = va_arg(*ap, int)) < 0)
			sign = -1;
		use_val(specs, ft_uitoa_base(ABS(value->ll_val), 10,specs->type), sign);
	}
	else if (specs->size == L)
		value->L_val = va_arg(*ap, int64_t);
}

	