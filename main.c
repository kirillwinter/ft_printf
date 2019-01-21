#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char s[] = "hui";
	char *s2 = NULL;
 	char c = '\0';
	unsigned long long a = 9223372036854775807;
	// int a = 128;
	// double d = -12454657.0615165156151;
	// d = 6.001465;
	// d =  921914941981.0;
	// d = 22.1;
	// printf("l010.5d\n");
	int pr;
	int ft;
	int prec = -2;
	int widht = -3;

	// TYPE d
	// ft_printf("%llhu\n", a);
	// printf("%llhu\n", a);
	ft_printf("$%####0000 5..1.10.#00d$\n", 256);
	printf("$%####0000 5..1.10.#00d$\n", 256);
	printf("$%0 5.1#d$\n", 256);
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("prec = %d	%#0.*lld$M\n", prec, prec, a);
	// 	pr = printf("prec = %d	%#0.*lld$O\n", prec, prec, a);
	// 	prec++;
	// }
	// prec = -2;
	// 	while (widht <= 8 )
	// {
	// 	ft = ft_printf("widht = %d	%#0*lld$M\n", widht, widht, a);
	// 	pr = printf("widht = %d	%#0*lld$O\n", widht, widht, a);
	// 	widht++;
	// }

	// TYPE x
	// prec = 5;
	// 	ft = ft_printf("prec = %d	%#0.*x$M\n", widht, prec, a);
	// 	pr = printf("prec = %d	%#0.*x$O\n", widht, prec, a);
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("prec = %d	%#0.*x$M\n", prec, prec, a);
	// 	pr = printf("prec = %d	%#0.*x$O\n", prec, prec, a);
	// 	prec++;
	// }
	// prec = -2;
	// 	while (widht <= 8 )
	// {
	// 	ft = ft_printf("widht = %d	%#0*x$M\n", widht, widht, a);
	// 	pr = printf("widht = %d	%#0*x$O\n", widht, widht, a);
	// 	widht++;
	// }

	// // TYPE u;
	// 	ft = ft_printf("prec = %d	%#0.*lu$M\n", prec, prec, a);
	// 	pr = printf("prec = %d	%#0.*lu$O\n", prec, prec, a);
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("prec = %d	%#0.*lu$M\n", prec, prec, a);
	// 	pr = printf("prec = %d	%#0.*lu$O\n", prec, prec, a);
	// 	prec++;
	// }
	// prec = -2;
	// 	while (widht <= 8 )
	// {
	// 	ft = ft_printf("widht = %d	%#0*lu$M\n", widht, widht, a);
	// 	pr = printf("widht = %d	%#0*lu$O\n", widht, widht, a);
	// 	widht++;
	// }
	// widht = -3;

	// TYPE o;
	// prec = 3;
	// 	ft = ft_printf("prec = %d	%#0.*o$M\n", prec, prec, a);
	// 	pr = printf("prec = %d	%#0.*o$O\n", prec, prec, a);
	// ft_printf("%#.o %#.0o$M\n", 0, 0);
	// printf("%#.o %#.0o$O\n", 0, 0);
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("prec = %d	%#0.*o$M\n", prec, prec, a);
	// 	pr = printf("prec = %d	%#0.*o$O\n", prec, prec, a);
	// 	prec++;
	// }
	// prec = -2;
	// 	while (widht <= 8 )
	// {
	// 	ft = ft_printf("widht = %d	%#0*o$M\n", widht, widht, a);
	// 	pr = printf("widht = %d	%#0*o$O\n", widht, widht, a);
	// 	widht++;
	// }

	// TYPE p
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("prec = %d	%0.*p$M\n", prec, prec, a);
	// 	pr = printf("prec = %d	%0.*p$O\n", prec, prec, a);
	// 	prec++;
	// }
	// widht = -3;

	// TYPE s
	// ft_printf("%010s is a string\n", "this");
	// printf("%010s is a string\n", "this");
	// ft = ft_printf("% #*.*s$M\n", widht, prec, s);
	// pr = printf("% #*.*s$O\n", widht, prec, s);
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("% #*.*s$M\n", widht, prec, s);
	// 	pr = printf("% #*.*s$O\n", widht, prec, s);
	// 	prec++;
	// }

	// TYPE c
	// ft = ft_printf("%c", NULL);
	// pr = printf("%c", NULL);
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("% #*.*s$M\n", widht, prec, s);
	// 	pr = printf("% #*.*s$O\n", widht, prec, s);
	// 	prec++;
	// }

	// TYPE c
	// ft = ft_printf("%000   %\n", "test");
	// pr = printf("%000   %\n", "test");
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("% #*.*s$M\n", widht, prec, s);
	// 	pr = printf("% #*.*s$O\n", widht, prec, s);
	// 	prec++;
	// }


	printf("ft = %d\n", ft);
	printf("pr = %d\n", pr);
	return (0); 
}
