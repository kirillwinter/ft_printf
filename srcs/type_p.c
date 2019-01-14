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
	char				*res;
	unsigned long long	val;

	if (specs->flags[flag_zero] == 0)
		specs->flags[flag_zero] = 0;
	val = (unsigned long long)va_arg(*ap, void *);
	res = ft_strjoin("0x", ft_uitoa_base(val, 16));
	ft_putstr(res);
	free(res);
}