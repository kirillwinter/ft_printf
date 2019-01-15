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
	char				*afterDot;
	char				*beforeDot;
	size_t				digits;
	long long			int_num;
	unsigned long long	int_frac;

	int_num = num;
	int_frac = (num - int_num) * ft_power(10, POWER(PREC(precision)));
	digits = ft_doublelen(int_num, int_frac);
	str = ft_strnew(digits);
	beforeDot = ft_itoa_base(int_num, 10);
	afterDot = ft_uitoa_base(int_frac, 10);
	str = ft_strcpy(str, beforeDot);
	str = ft_strcat(str, ".");
	str = ft_strcat(str, afterDot);
	free(beforeDot);
	free(afterDot);
	return (str);
}

void			print_type_fF(f_specs *specs, va_list *ap)
{
	char	*res;
	double	f;

	f = va_arg(*ap, double);
	res = ft_dtoa(f, specs->precision);
	ft_putstr(res);
	free(res);
}
