/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 21:03:20 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/17 21:03:22 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_dtoa_a_hex(double num, double orig_num, int precision, int ex)
{
	char				*str;
	char				*part_num;
	unsigned long long	int_num;
	double				int_frac;

	int_num = (unsigned long long)ABS(num);
	if (precision == 0)
	{
		if (orig_num - ft_power(2, ex) > ft_power(2, ex + 1) - orig_num)// оригинальная сучка иногда выводит 0х2 при нулевой точности, 
			int_num = 2;//													это костыль для таких случаев
		str = ft_itoa_base(int_num, 16);
	}
	else
	{
		part_num = ft_uitoa_base(int_num, 16);
		// if (orig_num != 0)
			str = ft_strjoin_free(part_num, ".", 1);
		int_frac = ABS(num) - int_num;
		part_num = ft_frac_base(int_frac, precision, 16);
		if ((int)ft_strlen(part_num) < precision)
			part_num = filling_zero(part_num, precision - ft_strlen(part_num));
		str = ft_strjoin_free(str, part_num, 3);
	}
	if (precision == -1 || precision == 13)
		str = del_last_zeros(str);
	return (str);
}

char		*ft_dtoa_a(double num, f_specs *specs)
{
	int		ex;
	char	*val;
	double	orig_num;

	orig_num = num;
	ex = 0;
	if (num > 1 || num < -1)
		while (ABS(num) >= 2 && ++ex)
			num /= 2;
	else if (num != 0)
		while (ABS(num) < 1 && --ex)
			num *= 2;
	val = ft_dtoa_a_hex(num, orig_num, PREC_A(specs->precision), ex);
	// if (specs->flags[flag_sharp] && !ft_strchr(val, '.'))
	// 	val = ft_strjoin_free(val, ".", 1);
	val = ft_strjoin_free(val, "p", 1);
	if (ex >= 0)
		val = ft_strjoin_free(val, "+", 1);
	else
		val = ft_strjoin_free(val, "-", 1);
	val = ft_strjoin_free(val, ft_itoa(ABS(ex)), 3);
	val = ft_strjoin_free(STRIFNEG(num), val, 2);
	return (val);
}

void		print_type_a(f_specs *specs, va_list *ap)
{
	char		*val;
	long double	lnbr;
	double		nbr;
	

	if (specs->size == L)
	{
		lnbr = va_arg(*ap, long double);
		val = use_sval(specs, ft_dtoa_a(lnbr, specs), lnbr);
	}
	else
	{
		nbr = va_arg(*ap, double);
		val = use_sval(specs, ft_dtoa_a(nbr, specs), nbr);
	}
	if (specs->type == 'A')
		val = ft_str_toupper(val);
	print_value(specs, val, ft_strlen(val));






	// if (specs->size == L)
	// 	val = use_sval(specs, ft_dtoa_a(va_arg(*ap, long double), specs), nbr);
	// else
	// 	val = use_sval(specs, ft_dtoa_a(va_arg(*ap, double), specs), nbr);
	// if (specs->type == 'A')
	// 	val = ft_str_toupper(val);
	// print_value(specs, val, ft_strlen(val));
}
