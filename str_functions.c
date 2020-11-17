/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:33:34 by dchani            #+#    #+#             */
/*   Updated: 2020/11/17 20:35:44 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ft_strchrf(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char)*s);
		s++;
	}
	if (*s == c)
		return ((char)*s);
	return (0);
}

void		ft_strcpyf(char *dst, char *src, size_t dstsize)
{
	while (dstsize--)
		*dst++ = *src++;
}

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
