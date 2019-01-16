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

char	*handling_precision_di(f_specs *specs, int sign, char *val, int len_val)
{
	char *tmp_str;

	if (sign < 0)
		len_val--;
	tmp_str = ft_strnew(specs->precision - len_val);
	ft_memset(tmp_str, '0', specs->precision - len_val);
	val = ft_strjoin(tmp_str, val);
	free(tmp_str);
	if (sign < 0)
		val = ft_strjoin("-", val);
	if (specs->flags[flag_plus] && sign >= 0)
		val = ft_strjoin("+", val);
	else if (specs->flags[flag_space] && val[0] != '-')
		val = ft_strjoin(" ", val);
	return (val);
}


char	*handling_zero_flag_di(f_specs *specs, int sign, char *val, int len_val)
{
	char *tmp_str;

	tmp_str = ft_strnew(specs->width - len_val);
	ft_memset(tmp_str, '0', specs->width - len_val);
	val = ft_strjoin(tmp_str, val);
	free(tmp_str);
	if (sign < 0)
		val = ft_strjoin("-", val);
	if (specs->flags[flag_plus] && sign >= 0)
		val[0] = '+';
	else if (specs->flags[flag_space] && val[0] != '-')
		val[0] = ' ';
	return (val);
}

void	use_val_di(f_specs *specs, char *val, int sign)
{
	int len_val;
		
	len_val = ft_strlen(val);
	if (sign < 0)
		len_val++;
	if (specs->precision || specs->flags[flag_minus]) // игнорируем флаг 0 при наличии - или точности
		specs->flags[flag_zero] = 0;
	if (specs->precision && specs->precision >= len_val) // берем значение если точность существует
		val = handling_precision_di(specs, sign, val, len_val);
	else if (specs->flags[flag_zero] && specs->width > len_val) // обработка флага 0
		val = handling_zero_flag_di(specs, sign, val, len_val);
	else if (sign < 0)
		val = ft_strjoin_free("-", val, 2);
	else if (specs->flags[flag_plus] && sign >= 0) // обработка флага +
		val = ft_strjoin("+", val);
	else if (specs->flags[flag_space] && !specs->flags[flag_plus] && sign >= 0) // обработка флага ' '
		val = ft_strjoin(" ", val);
	len_val = ft_strlen(val);
	print_value(specs, val, len_val); // обработка флага - или вывод всех значений кроме флага 0
}

char	*re_val(char *val, int *sign)
{
	char *res;

	if (val[0] == '-')
	{
		(*sign) = -1;
		val++;
		res = ft_strcpy(res, val);
		return (res);
	}
	return (val);
}

void	print_type_di(f_specs *specs, va_list *ap)
{
	int			sign;
	long long	nbr;
	char		*val;

	sign = 0;
	nbr = va_arg(*ap, long long);
	if (specs->size == hh)	
		use_val_di(specs, re_val(ft_itoa_base((char)nbr, 10), &sign), sign);	
	else if (specs->size == h)
		use_val_di(specs, re_val(ft_itoa_base((short int)nbr, 10), &sign), sign);	
	else if (specs->size == l)
		use_val_di(specs, re_val(ft_itoa_base((long)nbr, 10), &sign), sign);
	else if (specs->size == ll)
		use_val_di(specs, re_val(ft_itoa_base((long long)nbr, 10), &sign), sign);
	// else if (specs->size == L)
	// 	use_val_di(specs, re_val(ft_itoa_base((int64_t)nbr, 10), &sign), sign);
	else
		use_val_di(specs, re_val(ft_itoa_base((int)nbr, 10), &sign), sign);	
		
}
