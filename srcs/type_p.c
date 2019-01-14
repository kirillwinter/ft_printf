/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:12:32 by jwillem-          #+#    #+#             */
/*   Updated: 2019/01/10 19:12:36 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handling_precision_p(f_specs *specs, char *val, int len)
{
	char				*tmp_str;

	tmp_str = ft_strnew(specs->precision - len);
	ft_memset(tmp_str, '0', specs->precision - len);
	val = ft_strjoin(tmp_str, val);
	free(tmp_str);
	return (val);
}

char	*handling_zero_p(f_specs *specs, char *val, int len)
{
	char				*tmp_str;

	tmp_str = ft_strnew(specs->width - len - 2);
	ft_memset(tmp_str, '0', specs->width - len - 2);
	val = ft_strjoin(tmp_str, val);
	free(tmp_str);
	return (val);
}

void	print_type_p(f_specs *specs, va_list *ap)
{
	char				*val;
	unsigned long long	nbr;
	int					len;

	nbr = (unsigned long long)va_arg(*ap, void *);
	val = ft_uitoa_base(nbr, 16);
	len = ft_strlen(val);
	if (specs->precision || specs->flags[flag_minus])
		specs->flags[flag_zero] = 0;
	if (specs->precision)
		val = handling_precision_p(specs, val, len);
	len = ft_strlen(val);
	if (specs->flags[flag_zero] && (specs->width - len - 2) > 0)
		val = handling_zero_p(specs, val, len);
	val = ft_strjoin("0x", val);
	len = ft_strlen(val);
	print_value(specs, val, len);
	free(val);
}
