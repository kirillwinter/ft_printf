#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("l010.5d\n");
	ft_printf("TEXT%0.12l15dHEY%-.**i%c", 4, 7, 10, 500, 'H');
	
	return (0);
} 