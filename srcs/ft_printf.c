/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:06:40 by wballaba          #+#    #+#             */
/*   Updated: 2018/12/26 15:06:42 by wballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*find_all_specifier(char *start_ptr, f_specs *specs, va_list *ap)
{
	while (*start_ptr != 'd' && *start_ptr != 'i' && *start_ptr != 'o'
		&& *start_ptr != 'u' && *start_ptr != 'x' && *start_ptr != 'X'
		&& *start_ptr != 'c' && *start_ptr != 's' && *start_ptr != 'p'
		&& *start_ptr != '%' && *start_ptr != 'n' && *start_ptr != 'D'
		&& *start_ptr != 'O' && *start_ptr != 'U' && *start_ptr != 'f'
		&& *start_ptr != 'F')
	{
		if (*start_ptr == '#' || *start_ptr == '0' || *start_ptr == '-'
			|| *start_ptr == '+' || *start_ptr == ' ')
			start_ptr = find_flag_specifier(start_ptr, specs);
		else if ((*start_ptr > '0' && *start_ptr <= '9') || *start_ptr == '*')
			start_ptr = find_widht_specifier(start_ptr, specs, ap);
		else if (*start_ptr == '.')
			start_ptr = find_precision_specifier(++start_ptr, specs, ap);
		else if (*start_ptr == 'l' || *start_ptr == 'h' || *start_ptr == 'L')
			start_ptr = find_size_specifier(start_ptr, specs);
		else
			return (--start_ptr);
	}
	start_ptr = find_type_specifier(start_ptr, specs);
	return (start_ptr);
}

void	find_start_specifier(char *format, va_list *ap)
{
	char	*start_ptr;
	size_t	i;
	f_specs	*specs;

	start_ptr = NULL;
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			specs = create_new_specs();
			start_ptr = format;
			format = find_all_specifier(start_ptr + 1, specs, ap);
			get_value(specs, ap);
		}
		else
		{
			ft_putchar(*format);
			g_len++;
		}
		format++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	g_len = 0;
	va_start(ap, format);
	find_start_specifier((char *)format, &ap);
	va_end(ap);
	return (g_len);
}
