#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char s[] = "HELLO";
	char c = 'C';
	int a = 250;
	double d = 23.45678;

	// printf("l010.5d\n");
	int pr;
	int ft;

	ft = ft_printf("%0$5d$\n", a);
	pr = printf("%0$5d$\n", a);


	printf("ft = %d\n", ft);
	printf("pr = %d\n", pr);
	// printf("het%hhi\n", 100);
	return (0);
}
