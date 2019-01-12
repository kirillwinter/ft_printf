#include <stdio.h>
#include "ft_printf.h"

int main()
{
	long long a = -10;
	// printf("l010.5d\n");

	ft_printf("het%+lldwor\n", a);
       printf("het%+lldwor\n", a);
	// printf("het%hhi\n", 100);
	return (0);
}