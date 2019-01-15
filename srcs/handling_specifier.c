/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:10:14 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/15 15:10:17 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char	*handling_precision(f_specs *specs, char *val, int len)
{
	char				*tmp_str;

	tmp_str = ft_strnew(specs->precision - len);
	ft_memset(tmp_str, '0', specs->precision - len);
	val = ft_strjoin(tmp_str, val);
	free(tmp_str);
	return (val);
}

char	*handling_zero(f_specs *specs, char *val, int len)
{
	char				*tmp_str;

	tmp_str = ft_strnew(specs->width - len);
	ft_memset(tmp_str, '0', specs->width - len);
	val = ft_strjoin(tmp_str, val);
	free(tmp_str);
	return (val);
}

char	*use_val(f_specs *specs, char *val)
{
	int len;

	len = ft_strlen(val);
	if (specs->precision || specs->flags[flag_minus])
		specs->flags[flag_zero] = 0;
	if (specs->precision)
		val = handling_precision(specs, val, len);
	len = ft_strlen(val);
	if (specs->flags[flag_zero] && (specs->width - len) > 0)
		val = handling_zero(specs, val, len);
	return (val);
}

char	*handling_size(f_specs *specs, unsigned long long nbr, int base)
{
	char	*val;
 
	if (specs->size == hh)
		val = use_val(specs, ft_itoa_base((unsigned char)nbr, base));
	else if (specs->size == h)
		val = use_val(specs, ft_itoa_base((unsigned short int)nbr, base));	
	else if (specs->size == l)
		val = use_val(specs, ft_itoa_base((unsigned long)nbr, base));
	else if (specs->size == ll)
		val = use_val(specs, ft_uitoa_base((unsigned long long int)nbr, base));
	// else if (specs->size == L)
	// 	val = use_val_o(specs, ft_itoa_base((unsigned int64_t)nbr, 8));
	else
		val = use_val(specs, ft_itoa_base((unsigned int)nbr, base));
	return (val);
}