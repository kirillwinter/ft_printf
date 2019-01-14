#include <stdio.h>
#include "ft_printf.h"

int main()
{
	// char s[] = "HELLO";
	char c = 'C';
	// printf("l010.5d\n");
	int pr;
	int ft;

	ft = ft_printf("%-05cH\n", c);
	pr = printf("%-05cH\n", c);



	printf("ft = %d\n", ft);
	printf("pr = %d\n", pr);
	// printf("het%hhi\n", 100);
	return (0);
}