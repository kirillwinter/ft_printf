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

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_specs
{
	char	flags;
	int		width;
	int		precision;
	int		size;
	char	type;
}				f_specs;

typedef struct	s_value
{
    int				i_val;
    long			l_val;
    char			c_val;
    short int		si_val;
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

f_specs	*create_new_specs(void);
t_value *create_new_value(void);
void	get_value(f_specs *specs, t_value *value, va_list *ap);
int		ft_printf(const char *format, ...);


#endif
