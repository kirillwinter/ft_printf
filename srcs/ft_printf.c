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

void	find_start_specifier(char *format, va_list *ap)
{
	char *start_ptr;
	size_t i;
	f_specs	*specs;
	t_value *value;

	start_ptr = NULL;
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			specs = create_new_specs();
			start_ptr = format;
			value = create_new_value();
			format = find_all_specifier(start_ptr + 1, specs, ap);
			get_value(specs, value, ap);
		}
		else 
			ft_putchar(*format);
		format++;
	}
	// printf("\nflag = %c\n", specs->flags);
	// printf("width = %d\n", specs->width);
	// printf("precision = %d\n", specs->precision);
	// printf("size = %d\n", specs->size);
	// printf("type = %c\n", specs->type);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	find_start_specifier((char *)format, &ap);
	
	va_end(ap);
	return (len);
}
