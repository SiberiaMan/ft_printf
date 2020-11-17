/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memsetting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:13:29 by dchani            #+#    #+#             */
/*   Updated: 2020/11/17 17:20:15 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				*ft_memsetf(void *b, int c, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		((unsigned char*)b)[i] = c;
		i++;
	}
	return (b);
}

void				*ft_callocf(size_t count, size_t size, char c)
{
	void	*ptr;

	ptr = (char*)malloc(count * size);
	if (!ptr)
		return (0);
	ft_memsetf(ptr, c, count * size);
	return (ptr);
}
