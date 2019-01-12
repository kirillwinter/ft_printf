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

void	print_value(f_specs *specs, char *val)
{
	int len_val;

	len_val = ft_strlen(val);
	if (!specs->flags[flag_zero])
	{
		if (specs->flags[flag_minus])
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
	else
		ft_putstr(val);
}

char	*handling_prec(f_specs *specs, t_value *value, char *val, int len_val)
{
	char *tmp_str;

	specs->flags[flag_zero] = 0;
	if (value->i_val < 0)
		len_val--;
	tmp_str = ft_strnew(specs->precision - len_val);
	ft_memset(tmp_str, '0', specs->precision - len_val);
	val = ft_strjoin(tmp_str, val);
	if (value->i_val < 0)
		val = ft_strjoin("-", val);
	return (val);
}


char	*handling_zero(f_specs *specs, t_value *value, char *val, int len_val)
{
	char *tmp_str;

	tmp_str = ft_strnew(specs->width - len_val);
	ft_memset(tmp_str, '0', specs->width - len_val);
	val = ft_strjoin(tmp_str, val);
	if (value->i_val < 0)
		val = ft_strjoin("-", val);
	if (specs->flags[flag_plus] && value->i_val >= 0)
		val[0] = '+';
	else if (specs->flags[flag_space] && val[0] != '-')
		val[0] = ' ';
	return (val);
}

void	print_type_di(f_specs *specs, t_value *value, va_list *ap)
{
	char *val;
	int len_val;
	
	len_val = 0;
	if (specs->size == 0 || specs->size == hh || specs->size == h)	
	{
		value->i_val = va_arg(*ap, int);
		val = ft_itoa(ABS(value->i_val));
		len_val = ft_strlen(val);
		if (value->i_val < 0)
			len_val++;
		if (specs->precision && specs->precision > len_val) // берем значение если точность существует
			val = handling_prec(specs, value, val, len_val);
		else if (specs->flags[flag_zero] && specs->width > len_val) // обработка флага 0
			val = handling_zero(specs, value, val, len_val);
		else if (value->i_val < 0)
			val = ft_strjoin("-", val);
		else if (specs->flags[flag_plus] && value->i_val >= 0) // обработка флага +
			val = ft_strjoin("+", val);
		else if (!specs->flags[flag_plus] && value->i_val >= 0 && specs->flags[flag_space]) // обработка флага ' '
			val = ft_strjoin(" ", val);
		print_value(specs, val); // обработка флага - или вывод всех значений кроме флага 0
	}
}
	// else if (specs->size == l)
	// {
	// 	value->l_val = va_arg(*ap, long);
	// 	ft_putstr(ft_itoa((int)value->l_val));
	// }
	// else if (specs->size == ll)
	// 	value->ll_val = va_arg(*ap, long long int);
	// else if (specs->size == L)
	// 	value->L_val = va_arg(*ap, int64_t);