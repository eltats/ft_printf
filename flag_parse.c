/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:28:47 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/28 22:01:03 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_pars_hash(t_print *print)
{
	int		j;

	j = print->i;
	print->hash = false;
	while (!ft_strchr("dioubxX", print->output[j]))
	{
		if (print->output[j] == '#')
		{
			print->hash = true;
			return (1);
		}
		j++;
	}
	return (0);
}

void	flag_pars_all_true(t_print *print, int j)
{
	if (print->output[j] == '-')
		print->minus = true;
	if (print->output[j] == ' ' && print->plus == false)
		print->space = true;
	if (print->output[j] == '+')
		print->plus = true;
	if (print->output[j] == '0' && print->minus == false \
	&& !ft_isdigit(print->output[j - 1]) && print->output[j - 1] != '.')
		print->zero = true;
}

int		flag_pars_all(t_print *print)
{
	int		j;

	j = print->i;
	print->minus = false;
	print->zero = false;
	print->space = false;
	print->plus = false;
	while (!ft_strchr("dioufbxXcsp", print->output[j]))
	{
		if (print->output[j] == '-' || print->output[j] == '+' \
		|| print->output[j] == ' ' || print->output[j] == '0')
			flag_pars_all_true(print, j);
		j++;
	}
	if (print->minus == true || print->space == true || \
	print->plus == true || print->zero == true)
		return (1);
	return (0);
}

void	ft_hashflags(t_print *print, t_width *wid)
{
	wid->hash = 0;
	if ((print->output[print->i] == 'x' || print->output[print->i] == 'X') \
	&& print->hash == true)
	{
		if (wid->filler == '0')
		{
			if (print->output[print->i] == 'x')
				write(print->fd, "0x", 2);
			else
				write(print->fd, "0X", 2);
			print->return_value += 2;
			wid->hash = -2;
			print->hash = false;
		}
	}
	wid->zeroplus = 0;
	if ((print->plus == true && print->digit_zero == false) || (print->space \
	== true && print->digit_zero == false) || print->digit_zero == true)
		wid->zeroplus = -1;
}

int		ft_modflags(t_print *print, bool *enter)
{
	if (*enter == true)
		return (0);
	*enter = true;
	if (print->plus == true || print->space == true || \
	print->digit_zero == true)
	{
		if (print->plus == true && print->digit_zero == false)
			write(print->fd, "+", 1);
		else if (print->space == true && print->digit_zero == false)
			write(print->fd, " ", 1);
		else if (print->digit_zero == true)
			write(print->fd, "-", 1);
		print->return_value += 1;
		return (1);
	}
	return (0);
}
