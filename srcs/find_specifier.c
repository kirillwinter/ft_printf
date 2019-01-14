/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:30:51 by wballaba          #+#    #+#             */
/*   Updated: 2019/01/10 14:30:52 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*find_size_specifier(char *start_ptr, f_specs *specs)
{
	if (*start_ptr == 'h' && *(start_ptr + 1) == 'h')
	{
		specs->size = hh;
		start_ptr++;
	}
	else if (*start_ptr == 'h' && *(start_ptr + 1) != 'h')
		specs->size = h;
	else if (*start_ptr == 'l' && *(start_ptr + 1) != 'l')
		specs->size = l;
	else if (*start_ptr == 'l' && *(start_ptr + 1) == 'l')
	{
		specs->size = ll;
		start_ptr++;
	}
	else if (*start_ptr == 'L')
		specs->size = L;
	start_ptr++;
	return (start_ptr);
}

char	*find_type_specifier(char *start_ptr, f_specs *specs)
{
	if (*start_ptr == 'd')
		specs->type = 'd';
	else if (*start_ptr == 'i')
		specs->type = 'i';
	else if (*start_ptr == 'o')
		specs->type = 'o';
	else if (*start_ptr == 'u')
		specs->type = 'u';
	else if (*start_ptr == 'x')
		specs->type = 'x';
	else if (*start_ptr == 'X')
		specs->type = 'X';
	else if (*start_ptr == 'c')
		specs->type = 'c';
	else if (*start_ptr == 's')
		specs->type = 's';
	else if (*start_ptr == 'p')
		specs->type = 'p';
	else if (*start_ptr == '%')
		specs->type = '%';
	return (start_ptr);
}

char	*find_widht_specifier(char *start_ptr, f_specs *specs, va_list *ap)
{
	if (*start_ptr == '*')
	{
		specs->width = va_arg(*ap, int);
		start_ptr++;
	}
	else
	{
		specs->width = ft_atoi(start_ptr);
		while (*start_ptr >= '0' && *start_ptr <= '9')
			start_ptr++;
	}
	return (start_ptr);
}

char	*find_precision_specifier(char *start_ptr, f_specs *specs, va_list *ap)
{
	if (*start_ptr == '*')
	{
		specs->precision = va_arg(*ap, int);
		start_ptr++;
	}
	else
	{
		specs->precision = ft_atoi(start_ptr);
		while (*start_ptr >= '0' && *start_ptr <= '9')
			start_ptr++;
	}
	return (start_ptr);
}

char	*find_flag_specifier(char *start_ptr, f_specs *specs)
{
	if (*start_ptr == '#')
		specs->flags[flag_sharp] = 1;
	else if (*start_ptr == '0')
		specs->flags[flag_zero] = 1;
	else if (*start_ptr == '-')
		specs->flags[flag_minus] = 1;
	else if (*start_ptr == '+')
		specs->flags[flag_plus] = 1;
	else if (*start_ptr == ' ')
		specs->flags[flag_space] = 1;
	start_ptr++;
	return (start_ptr);
}
