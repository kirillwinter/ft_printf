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
// 	tmp = ft_uitoa_base(nbr, 16);
// 	printf("f = %f\n", nbr);
// 	len = ft_strlen(tmp);
// 	int_nbr = len - precision;
// 	val = ft_strnew(len + 1);
// 	val = ft_strncpy(val, tmp, len - precision);
// 	val = ft_strjoin(val, ".");
// 	val = ft_strjoin(val, tmp + len - precision);
// 	return (val);
// }

// static char		*ft_dtoa_a(double num, int precision)
// {
// 	int ex;

// 	ex = 0;
// 	while (ABS(num) < 1)
// 	{
// 		num *=10;
// 	}

// }


void	print_type_a(f_specs *specs, va_list *ap)
{
	char	*val;
	int		sign;

	sign = 0;
	if (specs->size == L)
		val = use_sval(specs, ft_dtoa_e(va_arg(*ap,long double), specs->precision, specs));
	else
		val = use_sval(specs, ft_dtoa_e(va_arg(*ap, double), specs->precision, specs));
	if (specs->type == 'E')
	if (specs->type == 'E')
		val = ft_str_toupper(val);
	print_value(specs, val, ft_strlen(val));
}
