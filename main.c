#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char s[] = "hui";
	char *s2 = NULL;
 	char c = 'A';
	unsigned long long a = -10;
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


	// // TYPE e
	// printf("\n\nTYPE e\n");
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("prec = %d	%e$M\n", prec, prec, d);
	// 	pr = printf("prec = %d	%e$O\n", prec, prec, d);
	// 	prec++;
	// }
	// prec = -2;
	// while (widht <= 8 )
	// {
	// 	ft = ft_printf("widht = %d	%#0*lle$M\n", widht, widht, d);
	// 	pr = printf("widht = %d	%#0*lle$O\n", widht, widht, d);
	// 	widht++;
	// }
	// widht = -3;

	// // TYPE g
	// printf("\n\nTYPE g\n");
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("prec = %d	%g$M\n", prec, prec, d);
	// 	pr = printf("prec = %d	%g$O\n", prec, prec, d);
	// 	prec++;
	// }
	// prec = -2;
	// while (widht <= 8 )
	// {
	// 	ft = ft_printf("widht = %d	%#0*llg$M\n", widht, widht, d);
	// 	pr = printf("widht = %d	%#0*llg$O\n", widht, widht, d);
	// 	widht++;
	// }
	// widht = -3;


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

	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("prec = %d	%0.*o$M\n", prec, prec, a);
	// 	pr = printf("prec = %d	%0.*o$O\n", prec, prec, a);
	// 	prec++;
	// }
	// prec = -2;
	// 	while (widht <= 8 )
	// {
	// 	ft = ft_printf("widht = %d	%0*o$M\n", widht, widht, a);
	// 	pr = printf("widht = %d	%0*o$O\n", widht, widht, a);
	// 	widht++;
	// }
	// widht = -3;
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

	// TYPE p
	// ft = ft_printf("{% %}");
	// pr = printf("{% %}");
	// while (prec <= 8 )
	// {
	// 	ft = ft_printf("% #*.*s$M\n", widht, prec, s);
	// 	pr = printf("% #*.*s$O\n", widht, prec, s);
	// 	prec++;
	// }

	// ft = ft_printf("%.x %.0x\n", 42, 42);
	// pr = printf("%.x %.0x\n", 42, 42);;

	// ft = ft_printf("%#x\n", 42);
	// pr = printf("%#x\n", 42);



	// ft = ft_printf("%x\n", 0);
	// pr = printf("%x\n", 0);

	// ft = ft_printf("%.x %.0x\n", 0, 0);
	// pr = printf("%.x %.0x\n", 0, 0);;

	// ft = ft_printf("%#x\n", 0);
	// pr = printf("%#x\n", 0);


	// ft = ft_printf("%o\n", 0);
	// pr = printf("%o\n", 0);

	// ft = ft_printf("%.o %.0o\n", 0, 0);
	// pr = printf("%.o %.0o\n", 0, 0);;

	// ft = ft_printf("%#o\n", 0);
	// pr = printf("%#o\n", 0);

	// ft = ft_printf("%#.o %#.0o\n", 0, 0);
	// pr = printf("%#.o %#.0o\n", 0, 0);

	// ft_printf("%");
	// printf("%");

	// ft = ft_printf("{%15lZ}\n", 123);
	// pr = printf("{%15lZ}\n", 123);

	// ft_printf("%");
	// printf("%");

	// ft_printf("%#.o %#.0o", 0, 0);
	// printf("%#.o %#.0o", 0, 0);

	// int x = 42;
	// ft = ft_printf("%X\n", 12165165165134);
	
	// pr = printf("%X\n", 12165165165134);

	//LEAKS

	// ft_printf("\\n");
	// ft_printf("%%\\n");
	// ft_printf("%d\\n", 42);
	// ft_printf("%d%d\\n", 42, 41);
	// ft_printf("%d%d%d\\n", 42, 43, 44);
	// ft_printf("%ld\\n", 2147483647);
	// ft_printf("%lld\\n", 9223372036854775807);
	// ft_printf("%x\\n", 505);
	// ft_printf("%X\\n", 505);

	// ft_printf("%p\\n", &ft_printf);
	// ft_printf("%20.15d\\n", 54321);
	// ft_printf("%-10d\\n", 3);
	// ft_printf("% d\\n", 3);
	// ft_printf("%+d\\n", 3);
	// ft_printf("%010d\\n", 1);
	// ft_printf("%hhd\\n", 0);
	// ft_printf("%jd\\n", 9223372036854775807);
	// ft_printf("%zd\\n", 4294967295);
	// ft_printf("%\\n");
	// ft_printf("%U\\n", 4294967295);
	// ft_printf("%u\\n", 4294967295);
	// ft_printf("%o\\n", 40);
	// ft_printf("%%#08x\\n", 42);
	// ft_printf("%x\\n", 1000);
	// ft_printf("%#X\\n", 1000);
	// ft_printf("%s\\n", NULL);
	// ft_printf("%S\\n", L"ݗݜशব");
	// ft_printf("%s%s\\n", "test", "test");
	// ft_printf("%s%s%s\\n", "test", "test", "test");
	// ft_printf("%C\\n", 15000);
	// ft_printf("%lx", 4294967296);
	// ft_printf("{%#05.*g}M\n", 10, 42.2);
	// ft_printf("{%#05.*e}M\n", 10, 42.2);
	


	
	double x = - 2.4;
	prec = -2;
	// while (prec < 5)
	// {
	// 	x = - 10.4;
	// 	while (x < 11)
	// 	{
	// 		ft = ft_printf("prec = %d	x = %f	spec = e	{%+ 0#10.*e}M\n", prec, x, prec, x);
	// 		pr = printf("prec = %d	x = %f	spec = e	{%+ 0#10.*e}O\n", prec, x, prec, x);
	// 		ft = ft_printf("prec = %d	x = %f	spec = g	{%+ 0#10.*g}M\n", prec, x, prec, x);
	// 		pr = printf("prec = %d	x = %f	spec = g	{%+ 0#10.*g}O\n", prec, x, prec, x);
	// 		x += 0.4;
	// 	}
	// 	prec++;
	// }
	// x = 0.800000;
	// prec = 2;
	// ft = ft_printf("prec = %d	x = %f	spec = e	{%010.*e}M\n", prec, x, prec, x);
	// pr = printf("prec = %d	x = %f	spec = e	{%010.*e}O\n", prec, x, prec, x);
	// ft = ft_printf("prec = %d	x = %f	spec = g	{%010.*g}M\n", prec, x, prec, x);
	// pr = printf("prec = %d	x = %f	spec = g	{%010.*g}O\n", prec, x, prec, x);


	prec = -2;
	// while (prec < 5)
	// {
	// 	x = - 10.4;
	// 	while (x < 11)
	// 	{
	// 		ft = ft_printf("prec = %d	x = %f	spec = e	{%010.*e}M\n", prec, x, prec, x);
	// 		pr = printf("prec = %d	x = %f	spec = e	{%010.*e}O\n", prec, x, prec, x);
	// 		ft = ft_printf("prec = %d	x = %f	spec = g	{%010.*g}M\n", prec, x, prec, x);
	// 		pr = printf("prec = %d	x = %f	spec = g	{%010.*g}O\n", prec, x, prec, x);
	// 		x += 0.4;
	// 	}
	// 	prec++;
	// }



	// prec = 2;
	// x = 10.000000;
	// // ft = ft_printf("{%#010.*e}M\n", prec, x);
	// // pr = printf("{%#010.*e}O\n", prec, x);
	// ft = ft_printf("{%#05.*g}M\n", prec, x);
	// pr = printf("{%#05.*g}O\n", prec, x);

	// //  ft_printf("%0+5d\n", 42);
	// ft_printf("% +10.5g\n", x);
	// printf("% +10.5g\n", x);


	// ft = ft_printf("{%*c}\n", -15, 0);
	// pr = printf("{%*c}\n", -15, 0);

	// ft_printf("%016b\n", 999);
	// wchar_t w = 90;
	// write(1, &w, 2);

	// char happy[] = { 11000010, 10100010};
	// write(1, happy, 2);

	// TYPE A
	// while (prec < 5)
	// {
	// 	x = - 10.4;
	// 	while (x < 11)
	// 	{
	// 		ft = ft_printf("prec = %d	x = %f	spec = e	{%020.*a}M\n", prec, x, prec, x);
	// 		pr = printf("prec = %d	x = %f	spec = e	{%020.*a}O\n", prec, x, prec, x);
	// 		// ft = ft_printf("prec = %d	x = %f	spec = g	{%010.*g}M\n", prec, x, prec, x);
	// 		// pr = printf("prec = %d	x = %f	spec = g	{%010.*g}O\n", prec, x, prec, x);
	// 		x += 0.4;
	// 	}
	// 	prec++;
	// }


	x = -10.4;
	// ft = ft_printf("%#.0a\n", x);
	// pr = printf("%#.0a\n", x);

	ft = ft_printf("%020.10aM\n", x);
	pr = printf("%020.10aO\n", x);

	// ft = ft_printf("%#.5o\n", 0);
	// pr = printf("%#.5o\n", 0);

	// ft = ft_printf("%#.0o\n", 0);
	// pr = printf("%#.0o\n", 0);

	// ft = ft_printf("{%0.13*e}\n", 5, 42.42);
	// pr = printf("{%0.13*e}\n", 5, 42.42);

	// ft = ft_printf("{%0*a}\n", 5, 42);
	// pr = printf("{%0*a}\n", 5, 42);

	// ft_printf("{%*c}", -15, 0);
	// printf("{%*c}", -15, 0);

	// printf("ft = %d\n", ft);
	// printf("pr = %d\n", pr);
	return (0); 
}
