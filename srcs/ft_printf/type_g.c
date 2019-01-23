/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 20:56:25 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/17 20:56:28 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*del_last_zeros(char *val)
{
	char	*str;
	size_t	i;

	if (!(str = ft_strdup(val)))
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != 'p')
		i++;
	while (str[--i] == '0')
		str[i] = '\0';
	free(val);
	return (str);
}

void			print_type_g(f_specs *specs, va_list *ap)
{
	char		*val;
	long double	nbr;
	int			len;

	if (specs->size == L)
		nbr = va_arg(*ap, long double);
	else
		nbr = va_arg(*ap, double);
	specs->precision = PREC_F(specs->precision);
	len = ft_intlen(nbr);
	if (specs->precision >= len)
	{
		specs->precision = specs->precision - len;
		val = use_sval(specs, ft_dtoa_base(nbr, specs->precision, 10), nbr);
		if (specs->flags[flag_sharp] && !ft_strchr(val, '.'))
			val = ft_strjoin_free(val, ".", 1);
	}
	else
	{
		if (specs->precision > 0)
			specs->precision--;
		val = use_sval(specs, ft_dtoa_e(nbr, specs), nbr);
	}
	val = del_last_zeros(val);
	print_value(specs, val, ft_strlen(val));
}
