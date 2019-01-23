/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_oux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:03:03 by jwillem-          #+#    #+#             */
/*   Updated: 2019/01/12 15:03:06 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type_oux(f_specs *specs, va_list *ap)
{
	unsigned long long	nbr;
	char				*val;

	nbr = va_arg(*ap, unsigned long long);
	if (specs->flags[flag_minus]) // игнорируем флаг 0 при наличии - или точности
		specs->flags[flag_zero] = 0;
	if (specs->type == 'o')
		val = handling_size(specs, nbr, 8);
	else if (specs->type == 'u')
		val = handling_size(specs, nbr, 10);
	else if (specs->type == 'b')
		val = handling_size(specs, nbr, 2);
	else if (specs->type == 'x' || specs->type == 'X')
		val = handling_size(specs, nbr, 16);
	if (specs->flags[flag_sharp])
	{
		if ((specs->type == 'x' || specs->type == 'X') && nbr)
				val = ft_strjoin_free("0x", val, 2);
		else if (specs->type == 'o' && (nbr != 0 || !specs->precision))
				val = ft_strjoin_free("0", val, 2);
	}
	if (specs->type == 'X')
		val = ft_str_toupper(val);
	print_value(specs, val, ft_strlen(val));
	// free(val);
}
