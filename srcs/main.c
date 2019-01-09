#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("l010.5d\n");
	ft_printf("hello%l010.5dsdfsdf%i", 5, 7);
	
	return (0);
}