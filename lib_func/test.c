#include "libft.h"
#include "stdarg.h"
#include "stdio.h"

void testit(int i, ...)
{
	va_list argptr;
	va_start(argptr, i);
	double a;
	while (i--)
	{
		a = va_arg(argptr, double);

		printf("%f\n", a);
	}
	va_end(argptr);
}

int main()
{
	//testit(3, 23, 74.3, 78);
	//printf("HELLO %s \n	%% %kkk\n", "HELLO\n");
	int a = 25;
	printf("%hhd", a);
}
