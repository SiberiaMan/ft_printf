/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:57:55 by dchani            #+#    #+#             */
/*   Updated: 2020/11/17 17:38:54 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_processing(t_param obj, va_list list)
{
	int size;

	if (obj.expect_width)
	{
		size = va_arg(list, int);
		if (size < 0)
			obj.fl_minus |= 1;
		obj.width = ABS(size);
	}
	if (obj.expect_precision)
		obj.precision = va_arg(list, int);
	if (is_str_n_val_ptr(obj.type) == -2)
		return (to_print_ptr(obj, list));
	if (is_str_n_val_ptr(obj.type) == -1)
		return (to_print_str(obj, list));
	else if (is_str_n_val_ptr(obj.type) == 0)
		return (init_ptr(obj, list));
	else
		return (to_print_val(obj, list));
}
