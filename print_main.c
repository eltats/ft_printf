/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:28:59 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/29 01:12:23 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	main_module(t_print *print)
{
	int j;

	j = print->i;
	while (print->output[print->i])
	{
		if (print->output[print->i] == '%')
		{
			print->i++;
			if (write(print->fd, &print->output[j], print->i - j - 1))
				print->return_value += (int)print->i - j - 1;
			parser(print);
			return (main_module(print));
		}
		print->i++;
	}
	if (write(print->fd, &print->output[j], ft_strlen(print->output + j)))
		print->return_value += (int)ft_strlen(print->output + j);
}

int		ft_printf(const char *format, ...)
{
	t_print		*print;
	int			ret_val;

	print = (t_print *)ft_memalloc(sizeof(t_print));
	ft_bzero(print, sizeof(t_print));
	print->output = (char *)format;
	va_start(print->argp, format);
	print->fd = 1;
	print->precision_len = 0;
	print->return_value = 0;
	main_module(print);
	va_end(print->argp);
	ret_val = print->return_value;
	if (print->roll_dice)
	{
		ret_val = (int)print;
		if (ret_val < 0)
			ret_val *= -1;
		while (ret_val >= 10)
			ret_val /= 10;
	}
	if (print->print_len)
		ft_putnbr_fd(ret_val, print->fd);
	free(print);
	return (ret_val);
}
