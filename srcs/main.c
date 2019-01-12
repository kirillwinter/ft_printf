#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int a = 10;
	// printf("l010.5d\n");

	ft_printf("het%+dwor\n", a);
       printf("het%+dwor\n", a);
	// printf("het%hhi\n", 100);
	return (0);
}