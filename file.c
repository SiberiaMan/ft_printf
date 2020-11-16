
#include "ft_printf.h"


char	*init(void)
{
	char *ptr = (char*)malloc(sizeof(char) * 3);
	ptr[0] = 'N';
	ptr[1] = 'O';
	ptr[2] = '\0';
	return (ptr);
}

int main()
{
	printf("%d\n", printf("%----15c\n", 'd'));
	printf("============================\n");
	printf("%d\n", ft_printf("%----15c\n", 'd'));  
	printf("%d\n", printf("%-*.*s\n%-5.100s\n", 20, 5, "Hello", "World"));
    printf("============================\n");
    printf("%d\n", ft_printf("%-*.*s\n%-5.100s\n", 20, 5,  "Hello", "World"));
	printf("%d\n", printf("%5.c", 'c'));
    printf("============================\n");
    printf("%d\n", ft_printf("%5.c", 'c'));
	printf("%d\n", printf("%5.s", "Hello World"));
    printf("============================\n");
    printf("%d\n", ft_printf("%5.s", "Hello World"));
	//printf("%-5lf", 7594857.585995585585);

    printf("==============1=============\n");
	printf("%d\n" ,printf("% 2d\n", 12));
	printf("---------------------------\n");
	ft_printf("%d\n", ft_printf("% 2d\n", 12));
	printf("==============2=============\n");
	printf("%d\n", printf("%12.10d\n", 20));
	printf("---------------------------\n");
	ft_printf("%d\n", ft_printf("%12.10d\n", 20));
	printf("==============3=============\n");
	printf("%d\n", printf("%+3.5d\n", 12));
	printf("---------------------------\n");
	ft_printf("%d\n", ft_printf("%+3.5d\n", 12));
	printf("==============4=============\n");
	printf("%d\n", printf("%#.5x\n", 5));
	printf("---------------------------\n");
	ft_printf("%d\n", ft_printf("%#.5x\n", 5));
	printf("==============5=============\n");
	printf("%d\n", printf("%.3x\n", 60));
    printf("---------------------------\n");
    ft_printf("%d\n", ft_printf("%.3x\n", 60));
    printf("===============6===========\n");
	printf("%d\n", printf("%#10.5X\n", 8655));
    printf("---------------------------\n");
	ft_printf("%d\n", ft_printf("%#10.5X\n", 8655));
    printf("===============7===========\n");
    printf("%d\n", printf("%hhd\n", 78));
    printf("---------------------------\n");
    ft_printf("%d\n", ft_printf("%hhd\n", 78));
    printf("===============8===========\n");
    printf("%d\n", printf("%+030.15d", 889));
    printf("---------------------------\n");
    ft_printf("%d\n", ft_printf("%+030.15d", 889));
    printf("===============9===========\n");
    printf("%d\n", printf("% 05d\n", 889));
    printf("---------------------------\n");   // -> failed test
    ft_printf("%d\n", ft_printf("% 05d\n", 889));
}
