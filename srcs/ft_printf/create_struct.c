/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 22:25:20 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/08 22:25:22 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

f_specs	*create_new_specs(void)
{
	f_specs	*specs;
	int		i;

	i = -1;
	if (!(specs = (f_specs *)malloc(sizeof(f_specs))))
		return (NULL);
	while (++i < 5)
		specs->flags[i] = 0;
	specs->type = 0;
	specs->width = 0;
	specs->precision = -1;
	specs->size = 0;
	return (specs);
}
