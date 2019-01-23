/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwillem- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:57:16 by jwillem-          #+#    #+#             */
/*   Updated: 2019/01/07 13:57:20 by jwillem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define POWER(precision)	(precision > 48 ? 48 : precision)
# define PREC_F(precision)	(precision <= -1 ? 6 : precision)
# define PREC(precision)	(precision <= -1 ? 0 : precision)
# define PREC_A(precision)	(precision <= -1 ? 13 : precision)
# define STRIFNEG(num)		(num < 0 ? "-0x" : "0x")


# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

int		g_len;

typedef struct	s_specs
{
	int		flags[5];
	int		width;
	int		precision;
	int		size;
	char	type;
}				f_specs;

typedef enum e_size
{
    hh = 1,
	h,
	l,
	L,
	ll,
	j,
	z,
	t
}			e_size;

typedef enum e_flag
{
    flag_sharp,
	flag_zero,
	flag_minus,
	flag_plus,
	flag_space
}			e_flag;



f_specs	*create_new_specs(void);

void	find_start_specifier(char *format, va_list *ap);

char	*find_all_specifier(char *start_ptr, f_specs *specs, va_list *ap);
char	*find_size_specifier(char *start_ptr, f_specs *specs);
char	*find_type_specifier(char *start_ptr, f_specs *specs);
char	*find_widht_specifier(char *start_ptr, f_specs *specs, va_list *ap);
char	*find_precision_specifier(char *start_ptr, f_specs *specs, va_list *ap);
char	*find_flag_specifier(char *start_ptr, f_specs *specs);

char	*get_value(char *start_ptr, f_specs *specs, va_list *ap);
void	print_value(f_specs *specs, char *val, int len_val);
char	*re_val(char *val, int *sign);
char	*use_sval(f_specs *specs, char *val, long long nbr);

char	*handling_precision(f_specs *specs, char *val, int len);
char	*handling_zero(f_specs *specs, char *val, int len);
char	*handling_size(f_specs *specs, unsigned long long nb, int base);
char	*filling_zero(char *val, int len);

void	print_type_di(f_specs *specs, va_list *ap);
void	print_type_c(f_specs *specs, va_list *ap);
void	print_type_s(f_specs *specs, va_list *ap);
void	print_type_p(f_specs *specs, va_list *ap);
void	print_type_oux(f_specs *specs, va_list *ap);
void	print_type_percent(f_specs *specs);
void	print_type_f(f_specs *specs, va_list *ap);
void	print_type_e(f_specs *specs, va_list *ap);
void	print_type_a(f_specs *specs, va_list *ap);
void	print_type_g(f_specs *specs, va_list *ap);
char	*print_non_spec(char *start_ptr, f_specs *specs);

char	*ft_dtoa_base(double num, int precision, int base);
char	*ft_frac_base(double int_frac, int precision, int base);
char	*ft_dtoa_e(double num, f_specs *specs);
char	*del_last_zeros(char *val);

#endif
