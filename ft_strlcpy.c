/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:39:28 by dchani            #+#    #+#             */
/*   Updated: 2020/11/08 20:54:08 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_strcpyf(char *restrict dst,const char *restrict src, size_t dstsize)
{
	while(dstsize--)
		(*dst)++ = *(src)++;
	free(src);
}
