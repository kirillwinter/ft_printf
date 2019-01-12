#include <stdio.h>
#include "ft_printf.h"

int main()
{
	// char s[] = "HELLO";
	// char c = 'C';
	// printf("l010.5d\n");
	int pr;
	int ft;

	ft = ft_printf("h%05dw\n", 100);
	pr = printf("h%05dw\n", 100);



	printf("ft = %d\n", ft);
	printf("pr = %d\n", pr);
	// printf("het%hhi\n", 100);
	return (0);
}