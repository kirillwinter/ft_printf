#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char s[] = "HELLO";
	char c = 'C';
	int a = -3000;
	// printf("l010.5d\n");
	int pr;
	int ft;

	ft = ft_printf("%-hh5o$\n", a);
	pr = printf("%-hh5o$\n", a);



	printf("ft = %d\n", ft);
	printf("pr = %d\n", pr);
	// printf("het%hhi\n", 100);
	return (0);
}