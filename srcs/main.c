#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int a = -100;
	// printf("l010.5d\n");

	ft_printf("het% -6dwor\n", a);
	printf("het% -6dwor\n", a);
	// printf("het%5dwor\n", a);
	return (0);
}