/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ouxX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:03:03 by jwillem-          #+#    #+#             */
/*   Updated: 2019/01/12 15:03:06 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_str_toupper(char *str)
{
	char	*res;
	char	*start_res;
	
	res = ft_strnew(ft_strlen(str));
	start_res = res;
	while (*str)
	{
		if (*str >= 97 && *str <= 122)
			*res++ = *str++ - 32;
		else
			*res++ = *str++;
	}
	return (start_res);
}

void	print_type_ouxX(f_specs *specs, va_list *ap)
{
	unsigned long long	nbr;
	char				*val;
	int					len;

	specs->precision = PREC(specs->precision);

	nbr = va_arg(*ap, unsigned long long);
	if (specs->type == 'o')
		val = handling_size(specs, nbr, 8);
	else if (specs->type == 'u')
		val = handling_size(specs, nbr, 10);
	else if (specs->type == 'x')
		val = handling_size(specs, nbr, 16);
	else if (specs->type == 'X')
		val = ft_str_toupper(handling_size(specs, nbr, 16));
	len = ft_strlen(val);
	print_value(specs, val, len);
	free(val);
}