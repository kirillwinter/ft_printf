#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char s[] = "HELLO";
	char c = 60;
	int a = -250;
	double d = .45678;
	d =  921914941981.0;
	// d = 22.1;
	// printf("l010.5d\n");
	int pr;
	int ft;
	int prec = 0;

	ft = ft_printf("%.*a$M\n", prec, d);

	pr = printf("%.*a$O\n", prec, d);

	// ft = ft_printf("%s$M\n", s);
	// pr = printf("%s$O\n", s);


	printf("ft = %d\n", ft);
	printf("pr = %d\n", pr);
	// printf("het%hhi\n", 100);
	return (0);
}
