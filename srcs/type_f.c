// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:29:31 by jwillem-          #+#    #+#             */
/*   Updated: 2019/01/14 15:29:38 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_doublelen(long long int_num, unsigned long long int_frac)
{
	size_t	i;

	i = 0;
	if (int_num < 0)
		i++;
	if (int_num == 0)
		i++;
	while (int_num)
	{
		i++;
		int_num /= 10;
	}
	i++;  // за точку
	if (int_frac == 0)
		return (++i);
	while (int_frac % 10 == 0)
		int_frac /= 10;
	while (int_frac)
	{
		i++;
		int_frac /= 10;
	}
	return (i);
}

char		*ft_dtoa(double num, int precision)
{
	char				*str;
	char				*part_num;
	long long			int_num;
	unsigned long long	int_frac;
	unsigned long long	decs;

	if (precision == 0)
	{
		if (num < 0)
			num -= 0.5;
		else
			num += 0.5;
		str = ft_itoa_base(num, 10);
	}
	else
	{
		int_num = num;
		decs = ft_power(10, POWER(PREC_F(precision)));
		int_frac = (ABS((num - int_num) + 0.5 / decs) * decs);
		str = ft_strnew(ft_doublelen(int_num, int_frac));
		str = ft_strnew(precision);
		part_num = ft_itoa_base(int_num, 10);
		str = ft_strcpy(str, part_num);
		free(part_num);
		part_num = ft_uitoa_base(int_frac, 10);	
		str = ft_strcat(str, ".");
		str = ft_strcat(str, part_num);
		free(part_num);
	}
	return (str);
}

// char *my_dtoa(double nbr, int precision)
// {
// 	char	*val;
// 	int		i;
// 	int		len;
// 	char	*tmp;
// 	int 	int_nbr;
// 	double		decs;

// 	i = 0;
// 	decs = 0.5 / ft_power(10, precision);
// 	nbr = nbr + decs;
// 	while (i < precision)
// 	{
// 		nbr *= 10;
// 		i++;
// 		// if (i == precision)
// 		// 	nbr = nbr + 0.5;
// 	}
// 	// nbr = nbr + 0.5;
// 	// printf("f = %f\n", nbr);
// 	tmp = ft_uitoa_base(nbr, 10);
// 	len = ft_strlen(tmp);
// 	int_nbr = len - precision;
// 	val = ft_strnew(len + 1);
// 	val = ft_strncpy(val, tmp, len - precision);
// 	val = ft_strjoin(val, ".");
// 	val = ft_strjoin(val, tmp + len - precision);
// 	return (val);
// }

void			print_type_fF(f_specs *specs, va_list *ap)
{
	char	*val;
	int		sign;

	sign = 0;
	specs->precision = PREC_F(specs->precision);
	if (specs->size == L)
	{
		val = re_val(ft_dtoa(va_arg(*ap, long double), specs->precision), &sign);
		val = use_sval(specs, val, sign);
	}
	else
	{
		val = re_val(ft_dtoa(va_arg(*ap, double), specs->precision), &sign);
		val = use_sval(specs, val, sign);
	}
	print_value(specs, val, ft_strlen(val));
	// free(val);
}
