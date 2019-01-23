#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char s[] = "hui";
	char *s2 = NULL;
 	char c = '\0';
	unsigned long long a = 0;
	// int a = 128;
	double d = -12454657.0615165156151;
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
	// ft_printf("$%.d$\n", 256);
	// printf("$%.d$\n", 256);
	// printf("$%0 5.1#d$\n", 256);
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


	// TYPE e
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("prec = %d	%e$M\n", prec, prec, d);
	// 	pr = printf("prec = %d	%e$O\n", prec, prec, d);
	// 	prec++;
	// }
	// prec = -2;
	// while (widht <= 8 )
	// {
	// 	ft = ft_printf("widht = %d	%#0*lld$M\n", widht, widht, d);
	// 	pr = printf("widht = %d	%#0*lld$O\n", widht, widht, d);
	// 	widht++;
	// }

	// TYPE x
	// prec = 5;
	// widht = 5;
	// a = 42;
	// 	ft = ft_printf("widht = %d	%#0*x$M\n", widht, widht, a);
	// 	pr = printf("widht = %d	%#0*x$O\n", widht, widht, a);
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
	// widht = -3;

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

	while (prec <= 8 )
	{
		ft = ft_printf("prec = %d	%0.*o$M\n", prec, prec, a);
		pr = printf("prec = %d	%0.*o$O\n", prec, prec, a);
		prec++;
	}
	prec = -2;
		while (widht <= 8 )
	{
		ft = ft_printf("widht = %d	%0*o$M\n", widht, widht, a);
		pr = printf("widht = %d	%0*o$O\n", widht, widht, a);
		widht++;
	}
	widht = -3;
	while (prec <= 8 )
	{
		ft = ft_printf("prec = %d	%#0.*o$M\n", prec, prec, a);
		pr = printf("prec = %d	%#0.*o$O\n", prec, prec, a);
		prec++;
	}
	prec = -2;
		while (widht <= 8 )
	{
		ft = ft_printf("widht = %d	%#0*o$M\n", widht, widht, a);
		pr = printf("widht = %d	%#0*o$O\n", widht, widht, a);
		widht++;
	}

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

	// TYPE p
	// ft = ft_printf("{% %}");
	// pr = printf("{% %}");
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("% #*.*s$M\n", widht, prec, s);
	// 	pr = printf("% #*.*s$O\n", widht, prec, s);
	// 	prec++;
	// }


	ft = ft_printf("%x\n", 42);
	pr = printf("%x\n", 42);

	ft = ft_printf("%.x %.0x\n", 42, 42);
	pr = printf("%.x %.0x\n", 42, 42);;

	ft = ft_printf("%#x\n", 42);
	pr = printf("%#x\n", 42);



	ft = ft_printf("%x\n", 0);
	pr = printf("%x\n", 0);

	ft = ft_printf("%.x %.0x\n", 0, 0);
	pr = printf("%.x %.0x\n", 0, 0);;

	ft = ft_printf("%#x\n", 0);
	pr = printf("%#x\n", 0);


	ft = ft_printf("%o\n", 0);
	pr = printf("%o\n", 0);

	ft = ft_printf("%.o %.0o\n", 0, 0);
	pr = printf("%.o %.0o\n", 0, 0);;

	ft = ft_printf("%#o\n", 0);
	pr = printf("%#o\n", 0);

	ft = ft_printf("%#.o %#.0o\n", 0, 0);
	pr = printf("%#.o %#.0o\n", 0, 0);

	// ft_printf("%.s", "hello");


	printf("ft = %d\n", ft);
	printf("pr = %d\n", pr);
	return (0); 
}
