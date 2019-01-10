#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("l010.5d\n");

	ft_printf("TEXT%5dHEY\n", 500);
	printf("het%5dwor", 100);
	
	return (0);
}