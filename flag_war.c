/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_war.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:42:16 by dchani            #+#    #+#             */
/*   Updated: 2020/11/17 20:43:50 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flag_war(t_param *obj)
{
	if (obj->fl_minus && obj->fl_null)
		obj->fl_null = 0;
	if (obj->is_precision)
		obj->fl_null = 0;
	if (obj->is_negative && obj->fl_space)
		obj->fl_space = 0;
	if (obj->fl_plus && obj->fl_space)
		obj->fl_space = 0;
	if (obj->is_negative && obj->fl_plus)
		obj->fl_plus = 0;
}
