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
	ll,
	L
}			e_size;

typedef enum e_flag
{
    flag_sharp,
	flag_zero,
	flag_minus,
	flag_plus,
	flag_space
}			e_flag;

char	*ft_strjoin_free(char *s1, char *s2, int operation);

f_specs	*create_new_specs(void);

void	find_start_specifier(char *format, va_list *ap);

char	*find_all_specifier(char *start_ptr, f_specs *specs, va_list *ap);
char	*find_size_specifier(char *start_ptr, f_specs *specs);
char	*find_type_specifier(char *start_ptr, f_specs *specs);
char	*find_widht_specifier(char *start_ptr, f_specs *specs, va_list *ap);
char	*find_precision_specifier(char *start_ptr, f_specs *specs, va_list *ap);
char	*find_flag_specifier(char *start_ptr, f_specs *specs);

void	get_value(f_specs *specs, va_list *ap);
void	print_value(f_specs *specs, char *val, int len_val);
char	*re_val(char *val, int *sign);

char	*handling_precision(f_specs *specs, char *val, int len);
char	*handling_zero(f_specs *specs, char *val, int len);
char	*handling_size(f_specs *specs, unsigned long long nbr, int base);

void	print_type_di(f_specs *specs, va_list *ap);
void	print_type_c(f_specs *specs, va_list *ap);
void	print_type_s(f_specs *specs, va_list *ap);
void	print_type_p(f_specs *specs, va_list *ap);
void	print_type_o(f_specs *specs, va_list *ap);
void	print_type_ouxX(f_specs *specs, va_list *ap);
void	print_type_percent(f_specs *specs);
void	print_type_fF(f_specs *specs, va_list *ap);

char	*ft_uitoa_base(unsigned long long num, int base);

int		ft_printf(const char *format, ...);


#endif
