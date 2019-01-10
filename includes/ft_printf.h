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
# define ABS(n)        ((n < 0) ? -(n) : (n))

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_specs
{
	int		flags[5];
	int		width;
	int		precision;
	int		size;
	char	type;
}				f_specs;

typedef struct	s_value
{
	int				i_val;
	int				c_val;
	char			*s_val;
	unsigned long	p_val;
	long			l_val;
	long long int	ll_val;
	int64_t			L_val;    
}				t_value;

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

f_specs	*create_new_specs(void);
t_value *create_new_value(void);
char	*find_all_specifier(char *start_ptr, f_specs *specs, va_list *ap);
void	get_value(f_specs *specs, t_value *value, va_list *ap);

void	print_type_di(f_specs *specs, t_value *value, va_list *ap);
void	print_type_c(f_specs *specs, t_value *value, va_list *ap);
void	print_type_s(f_specs *specs, t_value *value, va_list *ap);
void	print_type_p(f_specs *specs, t_value *value, va_list *ap);

int		ft_printf(const char *format, ...);


#endif
