#include "ft_printf.h"

static char		*ft_frac_base(double int_frac, int precision, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(precision);
	while (i < precision)
	{
		if (int_frac * base < 10 && int_frac * base >= 1)
			str[i++] = (int)(int_frac * base) + '0';
		else if (int_frac * base >= 10 && int_frac * base >= 1)
			str[i++] = (int)(int_frac * base) + 87;
		else
			str[i++] = '0';
		int_frac = int_frac * base - (int)(int_frac * base);
	}
	return (str);
}

char			*ft_dtoa_base(double num, int precision, int base)
{
	char				*str;
	char				*part_num;
	unsigned long long	int_num;
	double				int_frac;

	if (precision == 0)
	{
		if (num < 0)
			num -= (base / 20);
		else
			num += (base / 20);
		str = ft_itoa_base(num, base);
	}
	else
	{
		if (num < 0)
		{
			int_num = (unsigned long long)(-num);
			part_num = ft_strjoin_free("-", ft_uitoa_base(int_num, base), 2);
		}
		else
		{
			int_num = (unsigned long long)num;
			part_num = ft_uitoa_base(int_num, base);
		}
		str = ft_strjoin_free(part_num, ".", 1);
		int_frac = ABS((num - int_num) + 0.5 / ft_power(10, POWER(precision)));
		part_num = ft_frac_base(int_frac, precision, base);
		if ((int)ft_strlen(part_num) < precision)
			part_num = filling_zero(part_num, precision - ft_strlen(part_num));
		str = ft_strjoin_free(str, part_num, 3);
	}
	return (str);
}

void			print_type_f(f_specs *specs, va_list *ap)
{
	char		*val;
	long double	nbr;

	specs->precision = PREC_F(specs->precision);
	if (specs->size == L)
	{
		nbr = va_arg(*ap,long double);
		val = use_sval(specs, ft_dtoa_base(nbr, specs->precision, 10), nbr);
	}
	else
	{
		nbr = va_arg(*ap,double);
		val = use_sval(specs, ft_dtoa_base(nbr, specs->precision, 10), nbr);
	}
	if (specs->flags[flag_sharp])
		if (!ft_strchr(val, '.'))
			val = ft_strjoin_free(val, ".", 1);
	print_value(specs, val, ft_strlen(val));
	// free(val);
}