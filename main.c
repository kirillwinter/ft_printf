#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char s[] = "hui";
	char c = 60;
	int a = 123;
	double d = -12454657.0615165156151;
	// d = 6.001465;
	// d =  921914941981.0;
	// d = 22.1;
	// printf("l010.5d\n");
	int pr;
	int ft;
	int prec = -1;
	int widht = 5;

	// ft = ft_printf("%.*x$M\n", prec, 45678);
	// pr = printf("%.*x$O\n", prec, 45678);
	ft_printf("%s\n", s);
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("% #*.*g$M\n", widht, prec, d);
	// 	pr = printf("% #*.*g$O\n", widht, prec, d);
	// 	prec++;
	// }
	// prec = -1;
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("% #*.*s$M\n", widht, prec, s);
	// 	pr = printf("% #*.*s$O\n", widht, prec, s);
	// 	prec++;
	// }

	// ft = ft_printf("% d$M\n", a);
	// pr = printf("% d$O\n", a);


	printf("ft = %d\n", ft);
	printf("pr = %d\n", pr);
	// printf("het%hhi\n", 100);
	return (0); 
}
