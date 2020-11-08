/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:01:25 by dchani            #+#    #+#             */
/*   Updated: 2020/11/08 20:54:07 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strcut(char *str, int n)
{
	int		len;
	char	*ptr;
	int		i;

	len = 0;
	i = 0;
	while (*str && n)
	{
		len++;
		str++;
		n--;
	}
	len = MIN(n, len);
	if ((ptr = (char*)malloc(sizeof(char) * len + 1)))
	{
		while (len--)
			ptr[i] = str[i++];
		ptr[i] = '\0';
		return (ptr);
	}
	return(0);
}

int			ft_strlen(const char *str)
{
	int len = 0;

	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

int			char_process(t_param obj, va_list list)
{
	int		min_buf;
	int		min_str;
	char	*str;
	char	*catch_str;

	min_buf = 1;
	min_buf = ((obj.width > min_buf) ? obj.width : min_buf);
	str = ft_callocf(sizeof(char), min_buf, ' ');
	if (str && obj.fl_minus)
		str[0] = (char)va_arg(list, char);
	else if (str)
		str[min_buf - 1] = va_arg(list, char);
	else
		return (0);
	to_print(str, min_buf);
	return (min_buf);
}

int			string_process(t_param obj, va_list list)
{
	int		min_buf;
	int		min_str;
	char	*str;
	char	*catch_str;

	catch_str = va_arg(list, char*);
	if (!catch_str)
		catch_str = "(null)";
	if (obj.precision)
	{
		catch_str = ft_strcut(va_arg(list, char*), obj.precision);
		min_buf = MAX(obj.width, ft_strlen(catch_str));
	}
	else
		min_buf = MAX(obj.width, ft_strlen(catch_str));
	str = ft_callocf(sizeof(char), min_buf, ' ');
	if (str && obj.fl_minus)
		ft_strcpyf(&(str[0]), catch_str, ft_strlen(catch_str));
	else if (str)
		ft_strcpyf(&(str[min_buf - ft_strlen(catch_str)]), catch_str
		ft_strlen(catch_str))
	else
		return (0);
	to_print(str, min_buf);
	return (min_buf);
}

int			to_print_str(t_param obj, va_list list)
{

	if (obj.type == 'c')
		return (char_process(obj, list));
	else
		return (string_process(obj, list));
}
