/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:19:22 by dchani            #+#    #+#             */
/*   Updated: 2020/11/12 20:41:42 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int         end_check(char *format, int *i)
{
    int cnt;
    int fl_l;
    int fl_h;

 	cnt = 0;
	fl_l = 0;
	fl_h = 0;
//	printf("%c\n%s\n", format[*i], "HERE");
	while (format[*i] && is_modifier(format[*i]))
	{
		cnt++;
		if (cnt > 2 || (fl_l && fl_h))
			return (0);
		if (format[*i] == 'l')
			fl_l = 1;
		if (format[*i] == 'h')
			fl_h = 1;
		(*i)++;
	}
//	printf("%c\n", format[*i]);
	if (format[*i] && is_type(format[*i]))
		return (1);
	return (0);
}

int			begin_check(char *format, int *i)
{
	int		fl_width;
	int		fl_precision;

	*i = *i + 1;
	fl_width = 0;
	fl_precision = 0;
//	printf("ME HERE\n");
	while (format[*i] && is_flag(format[*i]))
	{
//		printf("%s\n", "flag");
		(*i)++;
	}
	while (format[*i] && (format[*i] == '*'
	|| ('0' <= format[*i] && format[*i] <= '9')))
	{
		if (format[(*i)++] == '*' && fl_width)
			return (0);
		fl_width = 1;
	}
	if (format[*i] && format[*i] == '.')
	{
		*i = *i + 1;
		while (format[*i] && (format[*i] == '*' || ('0' <= format[*i]
		&& format[*i] <= '9')))
		{	
			if (format[(*i)++] == '*' && fl_precision)
				return(0);
			fl_precision = 1;
		}
	}
	return (end_check(format, i));
}

int			parser(char *format, va_list list)
{
	int i;
	int	cur;
	int	printing;
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
//			printf("%c\n", format[j+1]);
			printing = get_arg(format, j + 1, list);
			cur += printing;
			i++;
			//printf("LALLA\n");
		}
		else
		{
			cur+= ft_putcharf(format[j], 0);
			i = j;
			i++;
		}
	}
	return (cur);
}
