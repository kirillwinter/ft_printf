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
		val = handling_precision(specs, val, len);
	len = ft_strlen(val);
	if (specs->flags[flag_zero] && (specs->width - len - 2) > 0)
		val = handling_zero(specs, val, len + 2);
	val = ft_strjoin("0x", val);
	len = ft_strlen(val);
	print_value(specs, val, len);
	free(val);
}
