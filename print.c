/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:21:30 by dchani            #+#    #+#             */
/*   Updated: 2020/11/12 17:26:33 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putstrf(char *format, int len, int is_format)
{
	while (len--)
	{
		ft_putcharf(*format, is_format);
		format++;
	}
}

int			ft_putcharf(char c, int is_format)
{
	if (!(!is_format && c == '%'))
	{
		write(1, &c, 1);
		return (1);
	}
	return (0);
}

void		to_print(char *s, int min_buf)
{
	while(min_buf--)
	{
		ft_putcharf(*s, 1);
		s++;
	}
}
