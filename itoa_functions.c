#include "ft_printf.h"

int			ft_toupper(int c)
{
    if (('a' <= c) && (c <= 'z'))
        return (c - 32);
    return (c);
}

static int         value_length(size_t n, int length_base, int fl)
{
    int size;

    size = 0;
    if (!n)
        return (1);
    if (fl)
        size++;
    while (n)
    {
        size++;
        n /= length_base;
    }
    return (size);
}

static void        to_upper(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        str[i] = ft_toupper(str[i]);
        i++;
    }
}

char*       ft_itoa_unsigned_base(char *str, size_t n, char type)
{
    char       *ptr;
    int        size;
    int        len_base;

    len_base = ft_strlen(str);
    size = value_length(n, len_base, 0);
    if (type == 'X')
        to_upper(str);
    ptr = (char*)malloc(size);
    if (!ptr)
        return (0);
    if (!n)
        ptr[0] = '0';
    while (n)
    {
        ptr[size--] = (n % len_base) + str[0];
        n /= 16;
    }
    return (ptr);
}

char*       ft_itoa_signed_base(char *str, long long int n)
{
    char    *ptr;
    int     size;
    int     len_base;
    int     fl;

    len_base = ft_strlen(str);
    fl = (n < 0 ? 1 : 0);
    size = value_length(n, len_base, fl);
    ptr = (char*)malloc(size);
    if (!ptr)
        return (0);
    if (!n)
        ptr[0] = '0';
    while (n)
    {
        ptr[size--] = (n % 10) + str[0];
        n /= 10;
    }
    if (fl)
        ptr[0] = '-';
    return (ptr);
}
