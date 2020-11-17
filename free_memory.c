/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:45:14 by dchani            #+#    #+#             */
/*   Updated: 2020/11/17 18:47:44 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		free_mem(int n, ...)
{
	va_list		list;
	char		*ptr;

	va_start(list, n);
	while (n--)
	{
		ptr = (char*)va_arg(list, char*);
		free(ptr);
		ptr = 0;
	}
}
