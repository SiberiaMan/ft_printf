#include "ft_printf.h"

int             to_print_unsigned_val(t_param obj, va_list list)
{
   size_t               n;
   char*                str;

   if (obj.modifier == H)
       n = (unsigned short int)va_arg(list, unsigned int);
   else if (obj.modifier == HH)
       n = (unsigned char)va_arg(list, unsigned int);
   else if (obj.modifier == L)
       n = (unsigned long int)va_arg(list, unsigned long int);
   else if (obj.modifier == LL)
       n = (unsigned long long int)va_arg(list, unsigned long long int);
   else
       n = (unsigned int)va_arg(list, unsigned int);
   if (ft_strchrf("Xx", obj.type))
       str = ft_itoa_unsigned_base("0123456789abcdef", n, obj.type);
   else
       str = ft_itoa_unsigned_base("0123456789", n, obj.type);
}

int             to_print_signed_val(t_param obj, va_list list)
{
    long long int       n;
    char*               str;

    if (obj.modifier == H)
        n = (short int)va_arg(list, int);
    else if (obj.modifier == HH)
        n = (char)va_arg(list, int);
    else if (obj.modifier == L)
        n = (long int)va_arg(list, long int);
    else if (obj.modifier == LL)
        n = (long long int)va_arg(list, long long int);
    else
        n = (int)va_arg(list, int);
    str = ft_itoa_signed_base("0123456789", n);

}

int				to_print_val(t_param obj, va_list list)
{
    if (obj.is_unsigned)
        return(to_print_unsigned_val(obj, list));
    else
        return(to_print_signed_val(obj, list));
}