/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:46:14 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/17 18:46:16 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_dtoa_e(double num, int precision, f_specs *specs)
{
	int		ex;
	char	*val;

	ex = 0;
	if (num > 1 || num < -1)
		while (ABS(num) > 10 && ++ex)
			num /= 10;
	else
		while (ABS(num) < 1 && --ex)
			num *= 10;
	val = ft_dtoa(num, precision);
	if (specs->flags[flag_sharp])
		if (!ft_strchr(val, '.'))
			val = ft_strjoin_free(val, ".", 1);
	val = ft_strjoin_free(val, "e", 1);
	if (ex >= 0)
		val = ft_strjoin_free(val, "+", 1);
	else
		val = ft_strjoin_free(val, "-", 1);
	if (ABS(ex) >= 10)
		val = ft_strjoin_free(val, ft_itoa(ABS(ex)), 3);
	else
	{
		val = ft_strjoin_free(val, "0", 1);
		val = ft_strjoin_free(val, ft_itoa(ABS(ex)), 3);
	}
	return (val);
}

void			print_type_e(f_specs *specs, va_list *ap)
{
	char	*val;

	if (specs->size == L)
		val = use_sval(specs, ft_dtoa_e(va_arg(*ap,long double), specs->precision, specs));
	else
		val = use_sval(specs, ft_dtoa_e(va_arg(*ap, double), specs->precision, specs));
	if (specs->type == 'E')
		val = ft_str_toupper(val);
	print_value(specs, val, ft_strlen(val));
}
