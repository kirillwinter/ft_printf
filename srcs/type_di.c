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

char	*handling_precision(f_specs *specs, int sign, char *val, int len_val)
{
	char *tmp_str;

	specs->flags[flag_zero] = 0;
	if (sign < 0)
		len_val--;
	tmp_str = ft_strnew(specs->precision - len_val);
	ft_memset(tmp_str, '0', specs->precision - len_val);
	val = ft_strjoin(tmp_str, val);
	free(tmp_str);
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
	free(tmp_str);
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
	else if (specs->flags[flag_space] && !specs->flags[flag_plus] && sign >= 0) // обработка флага ' '
		val = ft_strjoin(" ", val);
	len_val = ft_strlen(val);
	print_value(specs, val, len_val); // обработка флага - или вывод всех значений кроме флага 0
}

void	print_type_di(f_specs *specs, va_list *ap)
{
	int		sign;
	ssize_t	val;

	sign = 0;
	if ((val = va_arg(*ap, ssize_t)) < 0)
		sign = -1;
	val = ABS(val);
	if (specs->size == hh)	
		use_val(specs, ft_uitoa_base((signed char)val, 10, specs->type), sign);
	else if (specs->size == h)	
		use_val(specs, ft_uitoa_base((short int)val, 10, specs->type), sign);
	else if (specs->size == l)
		use_val(specs, ft_uitoa_base((long)val, 10, specs->type), sign);
	else if (specs->size == ll)
		use_val(specs, ft_uitoa_base((long long)val, 10,specs->type), sign);
	else if (specs->size == L)
		use_val(specs, ft_uitoa_base((int64_t)val, 10,specs->type), sign);
	else
		use_val(specs, ft_uitoa_base((int)val, 10,specs->type), sign);	
}
