#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char s[] = "HELLO";
	char c = 60;
	int a = -250;
	double d = .45678;
	d =  0.0002345678901234567890;
	// printf("l010.5d\n");
	int pr;
	int ft;
	int prec = 3;

	ft = ft_printf("%.*E$M\n", prec, d);
	pr = printf("%.*E$O\n", prec, d);

	// ft = ft_printf("%s$M\n", s);
	// pr = printf("%s$O\n", s);


	printf("ft = %d\n", ft);
	printf("pr = %d\n", pr);
	// printf("het%hhi\n", 100);
	return (0);
}
