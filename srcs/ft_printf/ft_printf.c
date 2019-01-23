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
		&& *start_ptr != 'F' && *start_ptr != 'e' && *start_ptr != 'E'
		&& *start_ptr != 'a' && *start_ptr != 'A' && *start_ptr != 'b'
		&& *start_ptr != 'g' && *start_ptr != 'G')
	{
		if (*start_ptr == '#' || *start_ptr == '0' || *start_ptr == '-'
			|| *start_ptr == '+' || *start_ptr == ' ')
			start_ptr = find_flag_specifier(start_ptr, specs);
		else if ((*start_ptr > '0' && *start_ptr <= '9') || *start_ptr == '*')
			start_ptr = find_widht_specifier(start_ptr, specs, ap);
		else if (*start_ptr == '.')
			start_ptr = find_precision_specifier(++start_ptr, specs, ap);
		else if (*start_ptr == 'l' || *start_ptr == 'h' || *start_ptr == 'L'
			|| *start_ptr == 'j' || *start_ptr == 'z' || *start_ptr == 't')
			start_ptr = find_size_specifier(start_ptr, specs);
		else
		{
			find_type_specifier(start_ptr, specs);
			return (--start_ptr);
		}
	}
	start_ptr = find_type_specifier(start_ptr, specs);
	return (start_ptr);
}

void	find_start_specifier(char *format, va_list *ap)
{
	f_specs	*specs;

	while (*format)
	{
		if (*format == '%')
		{
			specs = create_new_specs();
			format = find_all_specifier(format + 1, specs, ap);
			if (specs->type)
				format = get_value(format, specs, ap);
			free(specs);
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
