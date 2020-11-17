/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:08:13 by dchani            #+#    #+#             */
/*   Updated: 2020/11/17 20:44:21 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_param		init_obj(void)
{
	t_param param;

	param = (t_param){
		.fl_null = 0,
		.fl_plus = 0,
		.fl_minus = 0,
		.fl_space = 0,
		.fl_octal = 0,
		.expect_width = 0,
		.width = 0,
		.expect_precision = 0,
		.precision = 0,
		.is_precision = 0,
		.modifier = NAN,
		.is_negative = 0,
		.is_unsigned = 0,
		.type = 0,
		.length = 0
	};
	return (param);
}

static	void		flag_assign(char *format, int *i, t_param *obj)
{
	if (format[*i] == '0')
		obj->fl_null = 1;
	if (format[*i] == '-')
		obj->fl_minus = 1;
	if (format[*i] == '+')
		obj->fl_plus = 1;
	if (format[*i] == ' ')
		obj->fl_space = 1;
	if (format[*i] == '#')
		obj->fl_octal = 1;
	(*i)++;
}

static	void		modifier_assign(char *format, int *i, t_param *obj)
{
	t_modifier mdf;

	mdf = NAN;
	if (format[*i] == 'l' && format[(*i) + 1] == 'l')
	{
		mdf = LL;
		(*i) += 2;
	}
	if (format[*i] == 'l' && format[(*i) + 1] != 'l')
	{
		mdf = L;
		(*i)++;
	}
	if (format[*i] == 'h' && format[(*i) + 1] == 'h')
	{
		mdf = HH;
		(*i) += 2;
	}
	if (format[*i] == 'h' && format[(*i) + 1] != 'h')
	{
		mdf = H;
		(*i)++;
	}
	obj->modifier = mdf;
}

static	void		assign(char *format, int i, t_param *obj)
{
	while (is_flag(format[i]))
		flag_assign(format, &i, obj);
	if (format[i] == '*')
	{
		obj->expect_width = 1;
		i++;
	}
	obj->width = ft_atoif(&(format[i]), &i);
	if (format[i] == '.' && format[i + 1] == '*')
	{
		obj->expect_precision = 1;
		i += 2;
	}
	else if (format[i] == '.')
	{
		i++;
		obj->is_precision = 1;
		obj->precision = ft_atoif(&(format[i]), &i);
	}
	modifier_assign(format, &i, obj);
	obj->is_unsigned = is_unsigned(format[i]);
	obj->type = format[i];
}

int					get_arg(char *format, int i, va_list list, int length)
{
	t_param obj;

	obj = init_obj();
	obj.length = length;
	assign(format, i, &obj);
	return (print_processing(obj, list));
}
