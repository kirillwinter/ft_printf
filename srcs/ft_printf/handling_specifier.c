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

char	*filling_zero(char *val, int len)
{
	char	*tmp_str;

	tmp_str = ft_strnew(len);
	ft_memset(tmp_str, '0', len);
	val = ft_strjoin_free(tmp_str, val, 1);
	return (val);
}

/*
** функции используются для спецификаторов difF
*/

char	*use_sval(f_specs *specs, char *val, long long nbr)
{
	int len;
	int		sign;

	sign = 0;
	if (nbr == 0 && specs->precision == 0)
			return (NULL);
	val = re_val(val, &sign);
	len = ft_strlen(val);
	if ((sign == -1 || specs->flags[flag_plus]) && specs->precision < 0)
		len++;
	if (specs->flags[flag_minus] || specs->precision >= 0) // игнорируем флаг 0 при наличии - или точности
		specs->flags[flag_zero] = 0;
	if (specs->precision && specs->precision > len) // берем значение если точность существует
		val = filling_zero(val, specs->precision - len);
	else if (specs->flags[flag_zero] && specs->width > len) // обработка флага 0
		val = filling_zero(val, specs->width - len);
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

char	*use_uval(f_specs *specs, char *val, unsigned long long nbr)
{
	int 	len;

	len = ft_strlen(val);
	if (nbr == 0)
	{
		if (specs->type != 'o')
			specs->flags[flag_sharp] = 0;
		if (specs->precision == 0)
			return (NULL);
	}
	if (specs->precision > 0 || specs->flags[flag_minus])
		specs->flags[flag_zero] = 0;
	if (specs->flags[flag_sharp] && specs->precision < 0)
	{
		if (specs->type == 'x' || specs->type == 'X')
			len += 2;
		else if (specs->type == 'o')
			len++;
	}
	if (specs->precision && specs->precision >= len)
		val = filling_zero(val, specs->precision - len);
	if (specs->flags[flag_zero] && (specs->width - len) > 0)
		val = filling_zero(val, specs->width - len);
	return (val);
}

char	*handling_size(f_specs *specs, unsigned long long nbr, int base)
{
	char	*val;

	if (specs->size == hh)
		val = use_uval(specs, ft_uitoa_base((unsigned char)nbr, base), nbr);
	else if (specs->size == h)
		val = use_uval(specs, ft_uitoa_base((unsigned short int)nbr, base), nbr);
	else if (specs->size == l)
		val = use_uval(specs, ft_uitoa_base((unsigned long long)nbr, base), nbr);
	else if (specs->size == ll)
		val = use_uval(specs, ft_uitoa_base((unsigned long long int)nbr, base), nbr);
	else if (specs->size == j)
		val = use_uval(specs, ft_uitoa_base((uintmax_t)nbr, base), nbr);
	else if (specs->size == z)
		val = use_uval(specs, ft_uitoa_base((size_t)nbr, base), nbr);
	else if (specs->size == t)
		val = use_uval(specs, ft_uitoa_base((uintptr_t)nbr, base), nbr);
	else
		val = use_uval(specs, ft_uitoa_base((unsigned int)nbr, base), nbr);
	return (val);
}
