/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchani <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:42:00 by dchani            #+#    #+#             */
/*   Updated: 2020/11/16 12:55:15 by dchani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define ABS(x) ((x) > 0 ? x : x * (-1))
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
	int                 fl_octal;
	int					expect_width;
	int					width;
	int					expect_precision;
	int					is_precision;
	int					precision;
	t_modifier			modifier;
	int					is_unsigned;
	int                 is_negative;
	char				type;
}						t_param;

int						ft_printf(char *format, ...);
int						ft_atoif(char *str, int *i);
int						is_flag(char c);
int						is_modifier(char c);
int						is_type(char c);
int						is_valid(char c);
char					ft_strchrf(char *s, int c);
void					*ft_callocf(size_t count, size_t size, char c);
void					*ft_memsetf(void *b, int c, size_t len);
void					ft_putstrf(char *format, int len, int is_format);
int						ft_putcharf(char c, int is_format);
void					to_print(char *s, int min_buf);
int						is_modifier(char c);
int						is_type(char c);
int						is_unsigned(char c);
int						is_str_n_val(char c);
int						print_processing(t_param obj, va_list list);
int						to_print_str(t_param obj, va_list list);
int						ft_strlen(const char *str);
void					ft_strcpyf(char *dst, char *src, size_t dstsize);
int						get_arg(char *format, int i, va_list list);
int						parser(char *format, va_list list);
int						to_print_val(t_param obj, va_list list);
char					*ft_itoa_signed_base(char *str, long long int n, t_param *obj);
char					*ft_itoa_unsigned_base(char *str, size_t n);
int                     print_value_begin(t_param obj, char *str);
int                     print_value_end(t_param obj, char *prec_ptr, int size, int fl_to_second);

#endif
