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

void	print_type_p(f_specs *specs, t_value *value, va_list *ap)
{
	char	*res;
	if (specs->flags[flag_zero] == 0)
		specs->flags[flag_zero] = 0;
	value->p_val = (unsigned long)va_arg(*ap, void *);
	res = ft_strjoin("0x", ft_uitoa_base(value->p_val, 16));
	ft_putstr(res);
}