/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:01:25 by dchani            #+#    #+#             */
/*   Updated: 2020/11/18 12:44:26 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char		*ft_strcut(char *str, int n)
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

static	int			char_process(t_param obj, va_list list)
{
	int		min_buf;
	char	*str;

	min_buf = 1;
	min_buf = ((obj.width > min_buf) ? obj.width : min_buf);
	if (obj.type == '%' && obj.fl_null && !obj.fl_minus)
		str = ft_callocf(sizeof(char), min_buf, '0');
	else
		str = ft_callocf(sizeof(char), min_buf, ' ');
	if (!str)
		return (0);
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

static	char		*prec_processing(t_param obj, char *catch_str,
					int *fl, int *min_buf)
{
	if (obj.is_precision && obj.precision >= 0)
	{
		catch_str = ft_strcut(catch_str, obj.precision);
		*min_buf = MAX(obj.width, ft_strlen(catch_str));
		*fl = 1;
		return (catch_str);
	}
	else
	{
		*min_buf = MAX(obj.width, ft_strlen(catch_str));
		return (catch_str);
	}
}

static	int			string_process(t_param obj, va_list list)
{
	int		min_buf;
	char	*str;
	char	*catch_str;
	int		fl;

	fl = 0;
	catch_str = va_arg(list, char*);
	if (!catch_str)
		catch_str = "(null)";
	catch_str = prec_processing(obj, catch_str, &fl, &min_buf);
	str = ft_callocf(sizeof(char), min_buf, ' ');
	if (str && obj.fl_minus)
		ft_strcpyf(&(str[0]), catch_str, ft_strlen(catch_str));
	else if (str)
		ft_strcpyf(&(str[min_buf - ft_strlen(catch_str)]), catch_str,
		ft_strlen(catch_str));
	else
		return (0);
	ft_putstrf(str, min_buf, 1);
	if (fl)
		free_mem(2, str, catch_str);
	else
		free_mem(1, str);
	return (min_buf);
}

int					to_print_str(t_param obj, va_list list)
{
	if (obj.type == 'c' || obj.type == '%')
		return (char_process(obj, list));
	else
		return (string_process(obj, list));
}
