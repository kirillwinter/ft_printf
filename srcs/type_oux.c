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

char	*ft_str_toupper(char *str)
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

void	print_type_oux(f_specs *specs, va_list *ap)
{
	unsigned long long	nbr;
	char				*val;
	int					len;

	nbr = va_arg(*ap, unsigned long long);
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
		if (specs->type == 'X')
			val = ft_strjoin_free("0X", val, 2);
		else if (specs->type == 'x' )
			val = ft_strjoin_free("0x", val, 2);
		else if (specs->type == 'o')
			val = ft_strjoin_free("0", val, 2);
	}
	len = ft_strlen(val);
	print_value(specs, val, len);
	// free(val);
}
