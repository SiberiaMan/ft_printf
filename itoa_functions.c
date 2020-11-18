/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:36:24 by dchani            #+#    #+#             */
/*   Updated: 2020/11/18 12:27:47 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			value_length_unsigned(size_t n, int length_base)
{
	int size;

	size = 0;
	if (!n)
		return (1);
	while (n)
	{
		size++;
		n /= length_base;
	}
	return (size);
}

static int			value_length_signed(long long int n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char				*ft_itoa_unsigned_base(char *str, size_t n)
{
	char		*ptr;
	int			size;
	int			len_base;

	len_base = ft_strlen(str);
	size = value_length_unsigned(n, len_base);
	ptr = (char*)malloc(size + 1);
	if (!ptr)
		return (0);
	ptr[size--] = '\0';
	if (!n)
		ptr[0] = '0';
	while (n)
	{
		ptr[size--] = str[n % len_base];
		n /= len_base;
	}
	return (ptr);
}

char				*ft_itoa_signed_base(char *str, long long int n,
					t_param *obj)
{
	char	*ptr;
	int		size;
	int		len_base;
	int		fl;

	len_base = ft_strlen(str);
	fl = (n < 0 ? 1 : 0);
	size = value_length_signed(n);
	ptr = (char*)malloc(size + 1);
	if (!ptr)
		return (0);
	ptr[size--] = '\0';
	if (!n)
		ptr[0] = '0';
	while (n)
	{
		ptr[size--] = ABS(n % len_base) + str[0];
		n /= len_base;
	}
	if (fl)
		obj->is_negative = 1;
	return (ptr);
}
