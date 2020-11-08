/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:42:00 by dchani            #+#    #+#             */
/*   Updated: 2020/11/08 20:54:10 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define ABS(x) ((x) > 0 ? x : (-x))
# define MIN(a, b) ((a > b) ? b : a)
# define MAX(a, b) ((a > b) ? a : b)
typedef	enum			e_modifier
{
	NAN = 0, L = 1, LL = 2, H = 3, HH = 4
}						t_modifier;

typedef	struct			s_param
{
	int					fl_null;
	int					fl_plus;
	int					fl_minus;
	int					fl_space;
	int					expect_width;
	int					width;
	int					expect_precision;
	int					precision;
	t_modifier			modifier;
	int					is_unsigned;
	char				type;
}						t_param;

int						ft_atoif(char *str, int *i);
int						is_flag(char c);
int						is_modifier(char c);
int						is_type(char c);
int						is_valid(char c);
char					ft_strchrf(char *s, int c);
void					*ft_callocf(size_t count, size_t size, char c);
void					*ft_memsetf(void *b, int c, size_t len);
void					ft_strcpyf(char *restrict dst, const char *restrict src,
						size_t dstsize);

#endif
