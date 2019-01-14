/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:32:18 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/14 19:32:19 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handling_precision_o(f_specs *specs, char *val, int len)
{
	char				*tmp_str;

	tmp_str = ft_strnew(specs->precision - len);
	ft_memset(tmp_str, '0', specs->precision - len);
	val = ft_strjoin(tmp_str, val);
	free(tmp_str);
	return (val);
}

char	*handling_zero_o(f_specs *specs, char *val, int len)
{
	char				*tmp_str;

	tmp_str = ft_strnew(specs->width - len);
	ft_memset(tmp_str, '0', specs->width - len);
	val = ft_strjoin(tmp_str, val);
	free(tmp_str);
	return (val);
}

char	*use_val_o(f_specs *specs, char *val)
{
	int len;

	len = ft_strlen(val);
	if (specs->precision || specs->flags[flag_minus])
		specs->flags[flag_zero] = 0;
	if (specs->precision)
		val = handling_precision_o(specs, val, len);
	len = ft_strlen(val);
	if (specs->flags[flag_zero] && (specs->width - len) > 0)
		val = handling_zero_o(specs, val, len);
	return (val);
}

void	print_type_o(f_specs *specs, va_list *ap)
{
	char				*val;
	long long	nbr;
	int					len;

	nbr = va_arg(*ap, long long);
	if (specs->size == hh)	
		val = use_val_o(specs, ft_itoa_base((unsigned char)nbr, 8));
	else if (specs->size == h)
		val = use_val_o(specs, ft_itoa_base((unsigned short int)nbr, 8));	
	else if (specs->size == l)
		val = use_val_o(specs, ft_itoa_base((unsigned long)nbr, 8));
	else if (specs->size == ll)
		val = use_val_o(specs, ft_uitoa_base((unsigned long long int)nbr, 8));
	// else if (specs->size == L)
	// 	val = use_val_o(specs, ft_itoa_base((unsigned int64_t)nbr, 8));
	else
		val = use_val_o(specs, ft_itoa_base((unsigned int)nbr, 8));
	len = ft_strlen(val);
	print_value(specs, val, len);
	free(val);
}