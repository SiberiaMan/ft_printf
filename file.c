
#include "ft_printf.h"

static	int			ft_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

static	int			nlen(int n, int fl)
{
	int	size;

	size = 0;
	if (fl)
		size++;
	if (n == 0)
		return (1);
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char				*ft_itoa(int n)
{
	char	*ptr;
	int		size;
	int		fl;

	fl = (n < 0) ? 1 : 0;
	size = nlen(n, fl);
	ptr = (char*)malloc(size + 1);
	if (!ptr)
		return (0);
	ptr[size--] = '\0';
	if (n == 0)
		ptr[0] = '0';
	while (n)
	{
		ptr[size--] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (fl)
		ptr[0] = '-';
	return (ptr);
}

/*void	print_params(int i, ...)
{
	va_list list;
	va_start(list, i);

	while (i--)
	{
		char c = va_arg(list, char);
	}
} */ 
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
	/*printf("%d\n", printf("%----15c\n", 'd'));
	printf("============================\n");
	printf("%d\n", ft_printf("%----15c\n", 'd')); */ 
	/*printf("%d\n", printf("%-*.*s\n%-5.100s\n", 20, 5, "Hello", "World"));
    printf("============================\n");
    printf("%d\n", ft_printf("%-*.*s\n%-5.100s\n", 20, 5,  "Hello", "World")); */
	/*printf("%d\n", printf("%5.c", 'c'));
    printf("============================\n");
    printf("%d\n", ft_printf("%5.c", 'c')); */
	printf("%d\n", printf("%5.s", "Hello World"));
    printf("============================\n");
    printf("%d\n", ft_printf("%5.s", "Hello World"));
	//printf("%-5lf", 7594857.585995585585);
}
