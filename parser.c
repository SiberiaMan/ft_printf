/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:19:22 by dchani            #+#    #+#             */
/*   Updated: 2020/11/17 20:44:31 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int					end_check(char *s, int *i)
{
	int cnt;
	int fl_l;
	int fl_h;

	cnt = 0;
	fl_l = 0;
	fl_h = 0;
	while (s[*i] && is_modifier(s[*i]))
	{
		cnt++;
		if (cnt > 2 || (fl_l && fl_h))
			return (0);
		if (s[*i] == 'l')
			fl_l = 1;
		if (s[*i] == 'h')
			fl_h = 1;
		(*i)++;
	}
	if (s[*i] && is_type(s[*i]))
		return (1);
	return (0);
}

static	int					begin_check(char *s, int *i)
{
	int		fl_width;
	int		fl_precision;

	*i = *i + 1;
	fl_width = 0;
	fl_precision = 0;
	while (s[*i] && is_flag(s[*i]))
		(*i)++;
	while (s[*i] && (s[*i] == '*' || ('0' <= s[*i] && s[*i] <= '9')))
	{
		if (s[(*i)++] == '*' && fl_width)
			return (0);
		fl_width = 1;
	}
	if (s[*i] && s[*i] == '.')
	{
		*i = *i + 1;
		while (s[*i] && (s[*i] == '*' || ('0' <= s[*i] && s[*i] <= '9')))
		{
			if (s[(*i)++] == '*' && fl_precision)
				return (0);
			fl_precision = 1;
		}
	}
	return (end_check(s, i));
}

int							parser(char *format, va_list list)
{
	int i;
	int	cur;
	int	j;

	i = 0;
	cur = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		j = i;
		if (format[i] == '%' && format[i + 1] && begin_check(format, &i))
		{
			cur += get_arg(format, j + 1, list, cur);
			i++;
		}
		else
		{
			cur += ft_putcharf(format[j], 0);
			i = j;
			i++;
		}
	}
	return (cur);
}
