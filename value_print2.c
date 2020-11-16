/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_print2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:22:53 by dchani            #+#    #+#             */
/*   Updated: 2020/11/16 15:22:55 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static  void                       flag_war(t_param *obj)
{
    if (obj->fl_minus && obj->fl_null)
        obj->fl_null = 0;
    if (obj->is_precision)
        obj->fl_null = 0;
    if (obj->is_negative && obj->fl_space)
        obj->fl_space = 0;
    if (obj->fl_plus && obj->fl_space)
        obj->fl_space = 0;
    if (obj->is_negative && obj->fl_plus)
        obj->fl_plus = 0;
}

static  int                     find_null(char *prec_ptr)
{
    int len;

    len = 0;
    while(*prec_ptr != '0')
    {
        len++;
        prec_ptr++;
    }

    return (len);
}

static  void                    apply_flags(t_param obj, char *prec_ptr)
{
    if (obj.fl_space)
        prec_ptr[0] = ' ';
    else if (obj.fl_octal )
    {
        prec_ptr[0] = '0';
        if (obj.type == 'x')
            prec_ptr[1] = 'x';
        else
            prec_ptr[1] = 'X';
    }
    else if (obj.fl_plus)
        prec_ptr[0] = '+';
    else if (obj.is_negative)
        prec_ptr[0] = '-';
}

int                     print_value_end(t_param obj, char *prec_ptr, int size, int fl_to_second)
{
    int     size_buff;
    char    *buff_ptr;

    if (fl_to_second) {
        size_buff = MAX(obj.width, size);
        if (!(buff_ptr = ft_callocf(size_buff, sizeof(char), (obj.fl_null == 1 ? '0' : ' '))))
            return (0);
        if (obj.width > size) {
            if (obj.fl_minus)
                ft_strcpyf(buff_ptr, prec_ptr, size);
            else
                ft_strcpyf(&buff_ptr[size_buff - size], prec_ptr, size); //free
        } else
            ft_strcpyf(buff_ptr, prec_ptr, size);
        ft_putstrf(buff_ptr, size_buff, 1);
    }
    else {
        ft_putstrf(prec_ptr, size, 1);
        size_buff = size;
    }
    return (size_buff);
}

int                     print_value_begin(t_param obj, char *str)
{
    char    *prec_ptr;
    int     size;
    int     fl_to_second;

    flag_war(&obj);
    fl_to_second = 1;
    if (!obj.precision && obj.width) {
        obj.precision = obj.width;
        fl_to_second = 0;
    }
    size = MAX(ft_strlen(str), obj.precision);
    if (obj.fl_space || obj.fl_plus || obj.is_negative || obj.fl_octal)
    {
        if (!(prec_ptr = ft_callocf(size +
                              ((ft_strchrf("xX", obj.type) && obj.fl_octal == 1 )? 2 : 1), sizeof(char), '0')))
            return (0);
        apply_flags(obj, prec_ptr);
        size = size + ((ft_strchrf("xX", obj.type) && obj.fl_octal == 1 )? 2 : 1);
    }
    else
        if (!(prec_ptr = ft_callocf(size, sizeof(char), '0')))
            return (0);
    if (obj.precision > ft_strlen(str))
        ft_strcpyf(&prec_ptr[size - ft_strlen(str)], str, ft_strlen(str));
    else
        ft_strcpyf(&prec_ptr[find_null(prec_ptr)], str, ft_strlen(str));
    return (print_value_end(obj, prec_ptr, size, fl_to_second));
}

