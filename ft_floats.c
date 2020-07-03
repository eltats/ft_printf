/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:32:40 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/29 01:13:36 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flt_c(t_flt *flot)
{
	flot->temp = flot->str;
	flot->str = ft_itoa(flot->qq);
	ft_strdel(&flot->temp);
	flot->temp = flot->str;
	flot->str = ft_strjoin(flot->temp, ".");
	ft_strdel(&flot->temp);
}

void	ft_flt(t_print *print, t_flt *flot)
{
	while (flot->drob >= 0.5 && flot->i && flot->str2[flot->i - 1] == '9')
	{
		flot->i--;
		flot->str2[flot->i] -= 9;
	}
	if (flot->i == 0)
	{
		flot->qq = ft_atoi(flot->str);
		if (print->digit_zero == true || flot->qq > 0)
			flot->qq += 1;
		else
			flot->qq -= 1;
		if (flot->qq < 0)
		{
			flot->qq *= -1;
			print->digit_zero = true;
		}
		ft_flt_c(flot);
	}
	flot->i--;
	flot->i >= 0 ? flot->str2[flot->i] += 1 : 0;
}

void	ft_else_fl(t_print *print, t_flt *flot)
{
	flot->qq = ft_atoi(flot->str);
	if (print->digit_zero == true || flot->qq > 0)
		flot->qq += 1;
	else
		flot->qq -= 1;
	if (flot->qq < 0)
	{
		flot->qq *= -1;
		print->digit_zero = true;
	}
	flot->str = ft_itoa(flot->qq);
}

void	ft_float2(t_print *print, t_flt *flot)
{
	float_utils(print);
	if (print->big_l)
		flot->flt = va_arg(print->argp, long double);
	else
		flot->flt = va_arg(print->argp, double);
	flot->res = (long long int)flot->flt;
	flot->drob = flot->flt - flot->res;
	if (flot->res < 0 && flot->res != (double)INT_MAX + 1 \
	&& flot->res != (double)INT_MIN - 1)
	{
		flot->res *= -1;
		print->digit_zero = true;
	}
	flot->str = ft_it_flt_l(flot->res, print);
	if (print->precision_len != 0 || print->hash)
	{
		flot->temp = flot->str;
		flot->str = ft_strjoin(flot->temp, ".");
		ft_strdel(&flot->temp);
	}
	if (flot->flt < 0 && flot->res == 0)
		print->digit_zero = true;
	flot->i = 0;
	flot->len = print->precision_len;
	flot->str2 = (char *)ft_memalloc(sizeof(char) * (print->precision_len + 1));
}

void	ft_float(t_print *print)
{
	t_flt		flot;

	ft_float2(print, &flot);
	if (flot.drob < 0)
		flot.drob *= -1;
	while (flot.len--)
	{
		flot.drob *= 10;
		flot.tmp = (int)flot.drob;
		flot.str2[flot.i] = (int)flot.drob + '0';
		flot.drob = flot.drob - flot.tmp;
		flot.i++;
	}
	if (flot.drob >= 0.5 && flot.str2[flot.i - 1] == '9')
		ft_flt(print, &flot);
	else if (flot.drob >= 0.5 && flot.str2[flot.i - 1] != '9' && \
	print->precision_len)
		flot.str2[--flot.i] += 1;
	else if (flot.drob >= 0.5 && print->precision_len == 0)
		ft_else_fl(print, &flot);
	flot.temp = flot.str;
	flot.str = ft_strjoin(flot.temp, flot.str2);
	ft_strdel(&flot.temp);
	ft_strdel(&flot.str2);
	ft_mainout(print, flot.str);
}
