/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:36:24 by dchani            #+#    #+#             */
/*   Updated: 2020/11/16 12:49:52 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_toupper(int c)
{
	if (('a' <= c) && (c <= 'z'))
		return (c - 32);
	return (c);
}

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

static int          value_length_signed(long long int n, int length_base)
{
    int size;

    size = 0;
    if (n == 0)
        return (1);
    while(n)
    {
        size++;
        n /= 10;
    }
    return (size);
}

static void			to_upper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
	    printf("%c\n", str[i]);
		str[i] = (char)(ft_toupper(str[i]));
		i++;
	}
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
		n /= 16;
	}
	return (ptr);
}

char				*ft_itoa_signed_base(char *str, long long int n, t_param *obj)
{
	char	*ptr;
	int		size;
	int		len_base;
	int		fl;

	len_base = ft_strlen(str);
	fl = (n < 0 ? 1 : 0);
	size = value_length_signed(n, len_base);
	ptr = (char*)malloc(size + 1);
	if (!ptr)
		return (0);
	ptr[size--] = '\0';
	if (!n)
		ptr[0] = '0';
	while (n)
	{
	    //printf("%c\n", ABS(n % 10) + str[0]);
		ptr[size--] = ABS(n % 10) + str[0];
		n /= 10;
	}
	if (fl)
		obj->is_negative = 1;
	return (ptr);
}