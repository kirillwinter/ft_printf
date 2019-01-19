#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char s[] = "HELLO";
	char c = 60;
	int a = 123;
	double d = 123.3;
	// d = 6.001465;
	// d =  921914941981.0;
	// d = 22.1;
	// printf("l010.5d\n");
	int pr;
	int ft;
	int prec = -1;
	int widht = 7;

	// ft = ft_printf("%.*x$M\n", prec, 45678);
	// pr = printf("%.*x$O\n", prec, 45678);
	
	
	ft = ft_printf("%*.*f$M\n", widht, prec, d);
	pr = printf("%*.*f$O\n", widht, prec, d);

	// ft = ft_printf("% d$M\n", a);
	// pr = printf("% d$O\n", a);


	printf("ft = %d\n", ft);
	printf("pr = %d\n", pr);
	// printf("het%hhi\n", 100);
	return (0); 
}
