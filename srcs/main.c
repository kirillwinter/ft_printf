#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char s[] = "HELLO";
	char c = 'C';
	long long a = 9223372036854775809;
	double d = 23.45678;

	// printf("l010.5d\n");
	int pr;
	int ft;

	ft = ft_printf("%f$\n", d);
	pr = printf("%f$\n", d);


	printf("ft = %d\n", ft);
	printf("pr = %d\n", pr);
	// printf("het%hhi\n", 100);
	return (0);
}
