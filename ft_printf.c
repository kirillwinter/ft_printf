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

char *find_start_specifier(char *format)
{
	char *start;

	start = NULL;
	while (*format)
	{
		if (*format == '%')
			return (start = format);
		else
		{
			ft_putchar(*format);
		}
		
	}
	return (start);
}

char find_type_specifier(char *format)
{
	format = find_start_specifier(format);
	while (*format)
	{
		if (*format == 's')
			return (*format);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	if (find_type_specifier((char *)format) == 's')
	{
		ft_putstr(va_arg(ap, char));
	}
	va_end(ap);
	return (len);
}
