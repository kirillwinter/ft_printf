#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char s[] = "HELLO";
	char c = 'C';
	int a = -250;
	double d = 23.45678;
	d = -987.654321;
	// printf("l010.5d\n");
	int pr;
	int ft;

	// ft = ft_printf("%6.5d$\n", a);
	// pr = printf("%6.5d$\n", a);

	ft = ft_printf("% 015.8f$\n", d);
	pr = printf("% 015.8f$\n", d);


	printf("ft = %d\n", ft);
	printf("pr = %d\n", pr);
	// printf("het%hhi\n", 100);
	return (0);
}
