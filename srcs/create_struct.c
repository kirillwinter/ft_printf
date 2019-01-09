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

	if (!(specs = (f_specs *)malloc(sizeof(f_specs))))
		return (NULL);
	// specs->next = NULL;
	return (specs);
}

