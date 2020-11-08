/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:19:22 by dchani            #+#    #+#             */
/*   Updated: 2020/11/08 16:39:40 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			begin_check(char *format, int i)
{
	int		fl_width;
	int		fl_precision;

	fl_width = 0;
	fl_precision = 0;
	while (format[i] && is_flag(format[i]))
		i++;
	while (format[i] && (format[i] == '*'
	|| ('0' <= format[i] && formait[i] <= '9')))
	{
		if (format[i++] == '*' && fl_width)
			return (0);
		fl_width = 1;
	}
	if (format[i] && format[i] == '.')
	{
		while (format[i + 1] && (format[i + 1] == '*' || ('0' <= format[i + 1]
		&& format[i + 1] <= '9')))
		{	
			if (format[i++] == '*' && fl_precision)
				return(0);
			fl_precision = 1;
		}
	}
	return (end_check(format, i));
}

int			end_check(char *format, int i)
{
	int cnt;
	fl_l;
	fl_h;

	cnt = 0;
	fl_l = 0;
	fl_h = 0;
	if (format[i] && format[i] == '.')
		i++;
	if (format[i] && is_modifier(format[i]))
	{
		cnt++;
		if (cnt > 2 || (fl_l && fl_h))
			return (0);
		if (format[i] == 'l')
			fl_l = 1;
		if (format[i] == 'h')
			fl_h = 1;
		i++;
	}
	if (format[i] && is_type(format[i]))
		return (1);
	return (0);
}

int			parser(char *format, va_list list)
{
	int i;
	int	cur;

	i = 0;
	cur = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] && begin_check(format, i + 1))
			cur += get_arg(format, i + 1, list);
		else
			ft_putcharf(format[i], 0);
		cur++;
		i++;
	}
	return (cur);
}
