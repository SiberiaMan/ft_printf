
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

    long int *x;
    long int a =  28;
    x = &a;

    printf("          START CHECK\n\n");
    printf("============================");
    printf("\n        STRING CHECKING \n");
    printf("===============1============\n");
	printf("%d\n", printf("%----15c\n", 'd'));
	printf("============================\n");
	ft_printf("%d\n", ft_printf("%----15c\n", 'd'));
    printf("===============2============\n");
	printf("%d\n", printf("%-*.*s\n%-5.100s\n", 20, 5, "Hello", "World"));
    printf("============================\n");
    ft_printf("%d\n", ft_printf("%-*.*s\n%-5.100s\n", 20, 5,  "Hello", "World"));
    printf("===============3============\n");
	printf("%d\n", printf("%5.c\n", 'c'));
    printf("============================\n");
    ft_printf("%d\n", ft_printf("%5.c\n", 'c'));
    printf("===============4============\n");
	printf("%d\n", printf("%5.s\n", "Hello World"));
    printf("============================\n");
    ft_printf("%d\n", ft_printf("%5.s\n", "Hello World"));
    printf("========END STRING CHECK========\n");
    printf("============================");
	printf("\n        VALUE CHECKING \n");
    printf("============================\n");

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
    printf("%d\n", printf("%+030.15d\n", 889));
    printf("---------------------------\n");
    ft_printf("%d\n", ft_printf("%+030.15d\n", 889));
    printf("===============9===========\n");
    printf("%d\n", printf("% 05d\n", 889));
    printf("---------------------------\n");   // -> failed test
    ft_printf("%d\n", ft_printf("% 05d\n", 889));
    printf("==============10===========\n");
    printf("%d\n", printf("%#-5x\n", 0));
    printf("---------------------------\n");
    ft_printf("%d\n", ft_printf("%#-5x\n", 0));// -> failed test || update -> not failed
    printf("==============11===========\n");
    printf("%d\n", printf("%#x", 0));
    printf("---------------------------\n");
    ft_printf("%d\n", ft_printf("%#x", 0));
    printf("==============12===========\n");
    printf("%d\n", printf("%-#12.4x\n", 156));
    printf("---------------------------\n");
    ft_printf("%d\n", ft_printf("%-#12.4x\n", 156));
    printf("==============13===========\n");
	printf("%d\n", printf("%#010x\n", 27));
    printf("---------------------------\n");
	ft_printf("%d\n", ft_printf("%#010x\n", 27));
    printf("==============14===========\n");
    printf("%d\n", printf("%#10.5X\n", 8655));
    printf("---------------------------\n");
    ft_printf("%d\n", ft_printf("%#10.5X\n", 8655));
    printf("==============15===========\n");
    printf("%d\n", printf("%.3x\n", 60));
    printf("---------------------------\n");
    ft_printf("%d\n", ft_printf("%.3x\n", 60));
    printf("==============16===========\n");
    printf("%d\n", printf("%3hhi\n", 'b'));
    ft_printf("--------------------------------\n");
    ft_printf("%d\n", ft_printf("%3hhi\n", 'b'));
    printf("==============17===========\n");
    printf("%d\n", printf("% 5d\n", 89));
    ft_printf("------------------------\n");
    ft_printf("%d\n", ft_printf("% 5d\n", 89));
    printf("==============18===========\n");
    printf("%d\n", printf("%#010x\n", 87));
    ft_printf("------------------------\n");
    ft_printf("%d\n", ft_printf("%#010x\n", 87));
    printf("==============19===========\n");
    printf("%d\n", printf("%010x\n", 87));
    ft_printf("------------------------\n");
    ft_printf("%d\n", ft_printf("%010x\n", 87));
    printf("==============20===========\n");
    printf("%d\n", printf("%#3x\n", 18));
    ft_printf("------------------------\n");
    ft_printf("%d\n", ft_printf("%#3x\n", 18));
    printf("==============21===========\n");
    printf("%d\n", printf("%+05d\n", 889));
    printf("---------------------------\n");   // -> failed test
    ft_printf("%d\n", ft_printf("%+05d\n", 889));
    printf("==============22===========\n");
    printf("Hello %n\n %d  %hhi\n", x, 67890, 'i');
    printf("---------------------------\n");
    ft_printf("Hello %n\n %d  %hhi\n", x, 67890, 'i');
    printf("==============23===========\n");
    printf("%d\n", printf("%-30.p\n", 0));
    printf("---------------------------\n");
    ft_printf("%d\n", ft_printf("%-30.p\n", 0));
    printf("==============25===========\n");
    printf("%*d\n %-s\n%-#012x\n", -10, 5, "Hello", 89);
    printf("---------------------------\n");
    ft_printf("%*d\n %-s\n%-#012x\n", -10, 5, "Hello", 89);
    printf("==============26===========\n");
    printf("END CHECK");
   //ft_printf("%-10.3s", "Hello");
    //printf("===============2============\n");
   // printf("%d\n", printf("%-*.*s\n%-5.100s\n", 20, 5, "Hello", "World"));
   // printf("============================\n");
    ft_printf("%d\n", ft_printf("%-*.*s\n%-5.100s\n", 20, 3,  "Hello", "World"));
}
