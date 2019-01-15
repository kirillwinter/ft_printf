#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char s[] = "HELLO";
	char c = 'C';
	int a = 100;
	// printf("l010.5d\n");
	int pr;
	int ft;

	ft = ft_printf("% hhd$\n", a);
	pr = printf("% hhd$\n", a);



	printf("ft = %d\n", ft);
	printf("pr = %d\n", pr);
	// printf("het%hhi\n", 100);
	return (0);
}
