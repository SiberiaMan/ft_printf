/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:16:18 by dchani            #+#    #+#             */
/*   Updated: 2020/11/17 20:16:52 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void			hex_apply(char *str)
{
	*str = '0';
	str++;
	*str = 'x';
}

static	void			start_begin(char *buff_ptr, char *str)
{
	hex_apply(&buff_ptr[0]);
	ft_strcpyf(&buff_ptr[2], str, ft_strlen(str));
}

static void				start_end(char *buff_ptr, char *str, int buff_size)
{
	hex_apply(&buff_ptr[buff_size - ft_strlen(str) - 2]);
	ft_strcpyf(&buff_ptr[buff_size - ft_strlen(str)], str, ft_strlen(str));
}

int						to_print_ptr(t_param obj, va_list list)
{
	void	*ptr;
	char	*str;
	int		buff_size;
	char	*buff_ptr;

	ptr = va_arg(list, void*);
	if (!ptr && obj.is_precision)
	{
		if (obj.fl_minus)
			return (ft_printf("%-*s", obj.width, "0x"));
		else
			return (ft_printf("%*s", obj.width, "0x"));
	}
	str = ft_itoa_unsigned_base("0123456789abcdef",
	(unsigned long long int)ptr);
	buff_size = MAX(ft_strlen(str) + 2, obj.width);
	if (!(buff_ptr = ft_callocf(buff_size, sizeof(char), ' ')))
		return (0);
	if (obj.fl_minus)
		start_begin(buff_ptr, str);
	else
		start_end(buff_ptr, str, buff_size);
	ft_putstrf(buff_ptr, buff_size, 1);
	free_mem(2, str, buff_ptr);
	return (buff_size);
}
