/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:01:25 by dchani            #+#    #+#             */
/*   Updated: 2020/11/17 19:15:30 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char		*ft_strcut(char *str, int n)
{
	int		len;
	char	*ptr;
	int		i;

	len = ft_strlen(str);
	i = 0;
	len = MIN(n, len);
	if ((ptr = (char*)malloc(sizeof(char) * len + 1)))
	{
		while (len--)
		{
			ptr[i] = str[i];
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (0);
}

int			char_process(t_param obj, va_list list)
{
	int		min_buf;
	char	*str;

	min_buf = 1;
	min_buf = ((obj.width > min_buf) ? obj.width : min_buf);
	str = ft_callocf(sizeof(char), min_buf, ' ');
	if (obj.type != '%' && str && obj.fl_minus)
		str[0] = (char)va_arg(list, int);
	else if (obj.type == '%' && str && obj.fl_minus)
		str[0] = '%';
	else if (str && obj.type != '%')
		str[min_buf - 1] = (char)va_arg(list, int);
	else if (str && obj.type == '%')
		str[min_buf - 1] = '%';
	else
		return (0);
	ft_putstrf(str, min_buf, 1);
	free_mem(1, str);
	return (min_buf);
}

int			string_process(t_param obj, va_list list)
{
	int		min_buf;
	char	*str;
	char	*catch_str;
	int     fl;

	fl = 0;
	catch_str = va_arg(list, char*);
	if (!catch_str)
		catch_str = "(null)";
	if (obj.is_precision)
	{
		catch_str = ft_strcut(catch_str, obj.precision);
		min_buf = MAX(obj.width, ft_strlen(catch_str));
	}
	else
		min_buf = MAX(obj.width, ft_strlen(catch_str));
	str = ft_callocf(sizeof(char), min_buf, ' ');
	if (str && obj.fl_minus)
		ft_strcpyf(&(str[0]), catch_str, ft_strlen(catch_str));
	else if (str)
		ft_strcpyf(&(str[min_buf - ft_strlen(catch_str)]), catch_str,
		ft_strlen(catch_str));
	else
		return (0);
	ft_putstrf(str, min_buf, 1);
	free_mem(1, str);
	return (min_buf);
}

int			to_print_str(t_param obj, va_list list)
{
	if (obj.type == 'c' || obj.type == '%')
		return (char_process(obj, list));
	else
		return (string_process(obj, list));
}
