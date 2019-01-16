/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_fF.c                                          :+:      :+:    :+:   */
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

static char		*ft_dtoa(double num, int precision)
{
	char				*str;
	char				*part_num;
	long long			int_num;
	unsigned long long	int_frac;
	unsigned long long	decs;

	int_num = num;
	decs = ft_power(10, POWER(PREC_F(precision)));
	int_frac = (ABS((num - int_num) + 0.5 / decs) * decs);
	str = ft_strnew(ft_doublelen(int_num, int_frac));
	part_num = ft_itoa_base(int_num, 10);
	str = ft_strcpy(str, part_num);
	free(part_num);
	part_num = ft_uitoa_base(int_frac, 10);	
	str = ft_strcat(str, ".");
	str = ft_strcat(str, part_num);
	free(part_num);
	return (str);
}

// char *my_dtoa(double nbr, int precision)
// {
// 	char	*val;
// 	int		i;
// 	int		len;
// 	char	*tmp;
// 	int 	int_nbr;

// 	i = 0;
// 	while (i < precision)
// 	{
// 		nbr *= 10;
// 		i++;
// 		// if (i == precision)
// 		// 	nbr = nbr + 0.5;
// 	}
// 	// nbr = nbr + 0.6;
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
	char	*res;
	float	f;

	// f = va_arg(*ap, double);
	// if (specs->precision < 6)
	// 	specs->precision = 6;
	// res = my_dtoa(f, specs->precision);
	if (specs->size != L)
		res = ft_dtoa(va_arg(*ap, double), specs->precision);
	else
	{
		res = ft_dtoa(va_arg(*ap, long double), specs->precision);
		// use_val_di(specs, re_val(res, &sign), sign);
	}
		
	// res = ft_dtoa(f, specs->precision);
	
	print_value(specs, res, ft_strlen(res));
	free(res);
}
