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
	char				*res;
	unsigned long long	val;

	if (specs->flags[flag_zero] == 0)
		specs->flags[flag_zero] = 0;
	val = va_arg(*ap, unsigned long long);
	if (specs->type == 'o')
		res = ft_uitoa_base(val, 8);
	else if (specs->type == 'u')
		res = ft_uitoa_base(val, 10);
	else if (specs->type == 'x')
		res = ft_uitoa_base(val, 16);
	else if (specs->type == 'X')
		res = ft_str_toupper(ft_uitoa_base(val, 16));
	ft_putstr(res);
	free(res);
}