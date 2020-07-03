/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 20:08:33 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/29 01:18:17 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

typedef struct		s_print
{
	va_list			argp;
	char			*output;
	char			*out;
	int				spec;
	int				i;
	int				return_value;
	int				mod;
	int				width;
	int				precision_len;
	int				fd;
	bool			big_l;
	bool			print_len;
	bool			roll_dice;
	bool			need_free;
	bool			octal;
	bool			digit_zero;
	bool			precision;
	bool			h;
	bool			hh;
	bool			ll;
	bool			l;
	bool			hash;
	bool			zero;
	bool			minus;
	bool			plus;
	bool			space;
}					t_print;

typedef struct		s_width
{
	char			*width;
	char			*str;
	int				width_len;
	int				hash;
	int				zeroplus;
	int				plus;
	int				hate_printf;
	char			filler;
}					t_width;

typedef struct		s_flt
{
	char			*temp;
	char			*str;
	char			*str2;
	long long int	tmp;
	long long int	res;
	long double		flt;
	long double		drob;
	long long int	qq;
	long long int	i;
	long long int	len;
}					t_flt;

void				float_utils(t_print *print);
int					ft_numss(long long int n);
char				*ft_it_flt_l(long long int n, t_print *print);
void				ft_flt_c(t_flt *flot);
void				ft_fd(t_print *print, void *res);
void				ft_float2(t_print *print, t_flt *flot);
void				ft_else_fl(t_print *print, t_flt *flot);
void				ft_flt(t_print *print, t_flt *flot);
int					ft_fl_len(long double flt);
void				ft_float(t_print *print);
void				ft_p_out(t_print *print);
void				ft_null_out(t_print *print, bool *enter);
char				*ft_digit_crips(t_print *print, char *str);
void				ft_wid_out(t_print *print, char *str, bool *enter);
void				ft_min_in_char(t_print *print, char c);
int					ft_itoa_helper(long long int n, long long int base);
char				*n_null_pred(char *res, t_print *print);
int					ft_itoa_helper_unsigned(unsigned long long int n, \
unsigned long long int base);
char				*ft_capitalize(char *str);
int					ft_itoa_helper16(unsigned long long int base);
void				main_module(t_print *print);
char				*ft_precision_correct(char *res, char *str, t_print *print);
void				precision_true(t_print *print, int j, int wid);
int					precision_pars(t_print *print);
void				ft_width(t_print *print, char *str, bool *enter, int spec);
void				ft_val_width(t_print *print, t_width *wid, char *str);
void				ft_true_wid(t_width *wid, bool *enter, \
int spec, t_print *print);
int					field_width(t_print *print);
int					modification_pars_h(t_print *print);
int					modification_pars_l(t_print *print);
void				parser(t_print *print);
int					ft_modflags(t_print *print, bool *enter);
void				ft_hashflags(t_print *print, t_width *wid);
int					flag_pars_all(t_print *print);
void				flag_pars_all_true(t_print *print, int j);
int					flag_pars_hash(t_print *print);
int					ft_check(t_print *print);
void				ft_mainout(t_print *print, char *str);
void				ft_main_wid_min(t_print *print, char *str, bool *enter);
void				ft_main_wid(t_print *print, char *str, bool *enter);
int					ft_shift(t_print *print);
void				excluser(t_print *print);
void				ft_fill(char *null);
void				ft_out_x(t_print *print);
char				*ft_kv(char *kv);
void				ft_charout(t_print *print, void	*res);
void				ft_stdout_hex(t_print *print, void *res);
void				ft_stdout_unsignedint(t_print *print, void *res);
void				ft_stdout_octal(t_print *print, void *res);
void				ft_stdout_digits(t_print *print, void *res);
char				*ft_itoa_long_unsigned(unsigned long long int n);
char				*ft_itoa_long(long long int n, t_print *print);
void				ft_mainout(t_print *print, char *str);
int					ft_strstrchr(char *str, char *symbols);
char				*ft_xflag(unsigned long long int n, \
unsigned long long int base, t_print *print);
void				ft_itoa_base_16(unsigned long long int n, \
unsigned long long int base, t_print *print);
char				*ft_itoa_base_unsigned(unsigned long long int n, \
unsigned long long int base, t_print *print);
void				ft_itoa_base(long long int n, \
long long int base, t_print *print);
void				ft_putnbr_unsigned_long_long(unsigned long long int n);
void				ft_putnbr_long_long(long long int n);
int					ft_printf(const char *format, ...);

#endif
