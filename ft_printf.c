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
	start_ptr++;
	return (start_ptr);
}

void	find_all_specifier(char *start_ptr, f_specs *specs)
{
	while (*start_ptr != 'd' || *start_ptr != 'i' || *start_ptr != 'o' 
		|| *start_ptr != 'u' || *start_ptr != 'x' || *start_ptr != 'X' 
		|| *start_ptr != 'c' || *start_ptr != 's' || *start_ptr != 'p' 
		|| *start_ptr != '%')
	{
		if (*start_ptr == '#' || *start_ptr == '0' || *start_ptr == '-'
		|| *start_ptr == '+' || *start_ptr == ' ') //find flag
		{
			specs->flags = *start_ptr;
			start_ptr++;
		}
		else if (*start_ptr > '0' && *start_ptr <= '9') // find width
		{
			specs->width = ft_atoi(start_ptr);
			while (*start_ptr >= '0' && *start_ptr <= '9')
				start_ptr++;
		}
		else if (*start_ptr == '.') // find precision
		{
			specs->precision = ft_atoi(++start_ptr);
			while (*start_ptr >= '0' && *start_ptr <= '9')
				start_ptr++;
		}
		else if (*start_ptr == 'l' || *start_ptr == 'h' || *start_ptr == 'L') // find size
			start_ptr = find_size_specifier(start_ptr, specs);
		else
			break ;
		// start_ptr++;
	}
	start_ptr = find_type_specifier(start_ptr, specs);
}

void	find_start_specifier(char *format)
{
	char *start_ptr;
	size_t i;
	f_specs	*specs;

	start_ptr = NULL;
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			specs = create_new_specs();
			start_ptr = format;
			find_all_specifier(start_ptr + 1, specs);
		}
		format++;
	}
	printf("flag = %c\n", specs->flags);
	printf("width = %d\n", specs->width);
	printf("precision = %d\n", specs->precision);
	printf("size = %d\n", specs->size);
	printf("type = %c\n", specs->type);
}

int		ft_printf(const char *format, ...)
{
	// va_list	ap;
	int		len;

	len = 0;
	// va_start(ap, format);
	// if (find_type_specifier((char *)format) == 's')
	// {
	// 	ft_putstr(va_arg(ap, char));
	// }
	// va_end(ap);
	find_start_specifier((char *)format);
	return (len);
}
