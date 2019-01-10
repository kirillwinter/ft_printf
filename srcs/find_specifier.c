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
	if (*start_ptr == 'h' && *start_ptr + 1 == 'h')
	{
		specs->size = hh;
		start_ptr++;
	}
	else if (*start_ptr == 'h' && *start_ptr + 1 != 'h')
		specs->size = h;
	else if (*start_ptr == 'l' && *start_ptr + 1 != 'l')
		specs->size = l;
	else if (*start_ptr == 'l' && *start_ptr + 1 == 'l')
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

char	*find_all_specifier(char *start_ptr, f_specs *specs, va_list *ap)
{
	while (*start_ptr != 'd' && *start_ptr != 'i' && *start_ptr != 'o' 
		&& *start_ptr != 'u' && *start_ptr != 'x' && *start_ptr != 'X' 
		&& *start_ptr != 'c' && *start_ptr != 's' && *start_ptr != 'p' 
		&& *start_ptr != '%')
	{
		if (*start_ptr == '#' || *start_ptr == '0' || *start_ptr == '-'
		|| *start_ptr == '+' || *start_ptr == ' ') //find flag
		{
			specs->flags = *start_ptr;
			start_ptr++;
		}
		else if ((*start_ptr > '0' && *start_ptr <= '9') || *start_ptr == '*') // find width
			start_ptr = find_widht_specifier(start_ptr, specs, ap);
		else if (*start_ptr == '.') // find precision
			start_ptr = find_precision_specifier(++start_ptr, specs, ap);
		else if (*start_ptr == 'l' || *start_ptr == 'h' || *start_ptr == 'L') // find size
			start_ptr = find_size_specifier(start_ptr, specs);
		else 
		{
			printf("error\n");
			return (NULL);
		}
	}
	start_ptr = find_type_specifier(start_ptr, specs);
	return (start_ptr);
}
