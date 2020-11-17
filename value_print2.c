/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_print2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:22:53 by dchani            #+#    #+#             */
/*   Updated: 2020/11/17 20:42:48 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			find_null(t_param obj)
{
	if (ft_strchrf("xX", obj.type) && obj.fl_octal == 1)
		return (2);
	else if (!obj.is_negative && !obj.fl_plus && !obj.fl_space)
		return (0);
	return (1);
}

static	void		apply_flags(t_param obj, char *prec_ptr)
{
	if (obj.fl_space)
		prec_ptr[0] = ' ';
	else if (obj.fl_octal)
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

static	int			print_value_end_prec(t_param obj, char *prec_ptr,
					int size, char *str)
{
	int		size_buff;
	char	*buff_ptr;

	size_buff = MAX(obj.width, size);
	if (!(buff_ptr = ft_callocf(size_buff, sizeof(char),
	(obj.fl_null == 1 ? '0' : ' '))))
		return (0);
	if (obj.width > size)
	{
		if (obj.fl_minus)
			ft_strcpyf(buff_ptr, prec_ptr, size);
		else
			ft_strcpyf(&buff_ptr[size_buff - size], prec_ptr, size);
	}
	else
		ft_strcpyf(buff_ptr, prec_ptr, size);
	ft_putstrf(buff_ptr, size_buff, 1);
	free_mem(3, prec_ptr, str, buff_ptr);
	return (size_buff);
}

static	int			print_value_end_width(t_param obj, char *str)
{
	char	*buff_ptr;
	int		add_size;
	int		buff_size;

	add_size = 0;
	if (obj.fl_octal)
		add_size = 2;
	else if (obj.fl_plus || obj.fl_space || obj.is_negative)
		add_size = 1;
	buff_size = MAX(ft_strlen(str) + add_size, obj.width);
	if (!(buff_ptr = (char*)ft_callocf(buff_size, sizeof(char), '0')))
		return (0);
	apply_flags(obj, buff_ptr);
	if (ft_strlen(str) > obj.width)
		ft_strcpyf(&buff_ptr[find_null(obj)], str, ft_strlen(str));
	else
		ft_strcpyf(&buff_ptr[buff_size - ft_strlen(str)], str, ft_strlen(str));
	ft_putstrf(buff_ptr, buff_size, 1);
	free_mem(2, buff_ptr, str);
	return (buff_size);
}

int					print_value_begin(t_param obj, char *str)
{
	char	*prec_ptr;
	int		size;

	flag_war(&obj);
	if (!obj.is_precision && (obj.fl_space || obj.fl_plus ||
	obj.is_negative || obj.fl_octal) && obj.fl_null)
		return (print_value_end_width(obj, str));
	size = MAX(ft_strlen(str), obj.precision);
	if (obj.fl_space || obj.fl_plus || obj.is_negative || obj.fl_octal)
	{
		if (!(prec_ptr = ft_callocf(size +
		((ft_strchrf("xX", obj.type) && obj.fl_octal == 1) ? 2 : 1),
		sizeof(char), '0')))
			return (0);
		apply_flags(obj, prec_ptr);
		size = size + ((ft_strchrf("xX", obj.type)
		&& obj.fl_octal == 1) ? 2 : 1);
	}
	else if (!(prec_ptr = ft_callocf(size, sizeof(char), '0')))
		return (0);
	if (obj.precision > ft_strlen(str))
		ft_strcpyf(&prec_ptr[size - ft_strlen(str)], str, ft_strlen(str));
	else
		ft_strcpyf(&prec_ptr[find_null(obj)], str, ft_strlen(str));
	return (print_value_end_prec(obj, prec_ptr, size, str));
}
