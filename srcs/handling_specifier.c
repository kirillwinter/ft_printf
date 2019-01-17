/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:10:14 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/15 15:10:17 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*re_val(char *val, int *sign)
{
	char *res;

	if (val[0] == '-')
	{
		(*sign) = -1;
		val++;
		res = ft_strnew(ft_strlen(val));
		res = ft_strcpy(res, val);
		return (res);
	}
	return (val);
}

char	*filling_zero(f_specs *specs, char *val, int len)
{
	char	*tmp_str;

	tmp_str = ft_strnew(len);
	ft_memset(tmp_str, '0', len);
	val = ft_strjoin_free(tmp_str, val, 3);
	return (val);
}

/*
** функции используются для спецификаторов difF
*/

char	*use_val_difF(f_specs *specs, char *val, int sign)
{
	int len;
		
	len = ft_strlen(val);
	if (specs->precision || specs->flags[flag_minus]) // игнорируем флаг 0 при наличии - или точности
		specs->flags[flag_zero] = 0;
	if (specs->precision && specs->precision >= len) // берем значение если точность существует
		val = filling_zero(specs, val, specs->precision - len);
	else if (specs->flags[flag_zero] && specs->width > len) // обработка флага 0
		val = filling_zero(specs, val, specs->width - len);
	if (sign < 0)
		val = ft_strjoin_free("-", val, 2);
	else if (specs->flags[flag_plus] && sign >= 0) // обработка флага +
		val = ft_strjoin_free("+", val, 2);
	else if (specs->flags[flag_space] && !specs->flags[flag_plus] && sign >= 0) // обработка флага ' '
		val = ft_strjoin_free(" ", val, 2);
	return (val);
}

/*
** функции используются для спецификаторов ouxX
*/

char	*use_val(f_specs *specs, char *val)
{
	int 	len;

	len = ft_strlen(val);
	if (specs->precision || specs->flags[flag_minus])
		specs->flags[flag_zero] = 0;
	if (specs->precision)
		val = filling_zero(specs, val, specs->precision - len);
	len = ft_strlen(val);
	if (specs->flags[flag_zero] && (specs->width - len) > 0)
		val = filling_zero(specs, val, specs->width - len);
	return (val);
}

char	*handling_size(f_specs *specs, unsigned long long nbr, int base)
{
	char	*val;

	if (specs->size == hh)
		val = use_val(specs, ft_itoa_base((unsigned char)nbr, base));
	else if (specs->size == h)
		val = use_val(specs, ft_itoa_base((unsigned short int)nbr, base));
	else if (specs->size == l)
		val = use_val(specs, ft_itoa_base((unsigned long)nbr, base));
	else if (specs->size == ll)
		val = use_val(specs, ft_uitoa_base((unsigned long long int)nbr, base));
	else if (specs->size == j)
		val = use_val(specs, ft_uitoa_base((uintmax_t)nbr, base));
	else if (specs->size == z)
		val = use_val(specs, ft_itoa_base((size_t)nbr, base));
	else if (specs->size == t)
		val = use_val(specs, ft_itoa_base((uintptr_t)nbr, base));
	else
		val = use_val(specs, ft_itoa_base((unsigned int)nbr, base));
	return (val);
}
