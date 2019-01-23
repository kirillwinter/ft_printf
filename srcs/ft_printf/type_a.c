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

static char	*ft_dtoa_a_hex(double num, int precision, int base)
{
	char				*str;
	char				*part_num;
	unsigned long long	int_num;
	double				int_frac;

	if (precision == 0)
		str = ft_itoa_base(num, base);
	else
	{
		if (num < 0)
			int_num = (unsigned long long)(-num);
		else
			int_num = (unsigned long long)num;
		part_num = ft_uitoa_base(int_num, base);
		str = ft_strjoin_free(part_num, ".", 1);
		int_frac = ABS(num) - int_num;
		part_num = ft_frac_base(int_frac, precision, base);
		if ((int)ft_strlen(part_num) < precision)
			part_num = filling_zero(part_num, precision - ft_strlen(part_num));
		str = ft_strjoin_free(str, part_num, 3);
	}
	str = del_last_zeros(str);
	return (str);
}

char		*ft_dtoa_a(double num, f_specs *specs)
{
	int		ex;
	char	*val;

	ex = 0;
	if (num > 1 || num < -1)
		while (ABS(num) > 2 && ++ex)
			num /= 2;
	else
		while (ABS(num) < 1 && --ex)
			num *= 2;
	val = ft_dtoa_a_hex(num, PREC_A(specs->precision), 16);
	if (specs->flags[flag_sharp] && !ft_strchr(val, '.'))
		val = ft_strjoin_free(val, ".", 1);
	val = ft_strjoin_free(val, "p", 1);
	if (ex >= 0)
		val = ft_strjoin_free(val, "+", 1);
	else
		val = ft_strjoin_free(val, "-", 1);
	if (ABS(ex) >= 10)
		val = ft_strjoin_free(val, ft_itoa(ABS(ex)), 3);
	else
		val = ft_strjoin_free(val, ft_itoa(ABS(ex)), 3);
	val = ft_strjoin_free(STRIFNEG(num), val, 2);
	return (val);
}

void		print_type_a(f_specs *specs, va_list *ap)
{
	char	*val;
	int		sign;
	double	nbr;
	
	sign = 0;
	if (specs->size == L)
		val = use_sval(specs, ft_dtoa_a(va_arg(*ap, long double), specs), nbr);
	else
		val = use_sval(specs, ft_dtoa_a(va_arg(*ap, double), specs), nbr);
	if (specs->type == 'A')
		val = ft_str_toupper(val);
	print_value(specs, val, ft_strlen(val));
}
