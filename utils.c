/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:28:41 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/28 22:17:51 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_kv(char *kv)
{
	kv = (char *)malloc(sizeof(char) * (1));
	kv[0] = '\0';
	return (kv);
}

void	ft_out_x(t_print *print)
{
	if (print->output[print->i] == 'x')
		print->hash == true ? write(print->fd, "0x", 2) : 0;
	else
		print->hash == true ? write(print->fd, "0X", 2) : 0;
	print->return_value += 2;
	print->hash = false;
}

void	ft_fill(char *null)
{
	null[0] = '(';
	null[1] = 'n';
	null[2] = 'u';
	null[3] = 'l';
	null[4] = 'l';
	null[5] = ')';
	null[6] = '\0';
}

void	excluser(t_print *print)
{
	if (print->output[print->i] == 'p' || print->output[print->i] \
	== 's' || print->output[print->i] == 'c')
	{
		print->zero = false;
		print->plus = false;
		print->hash = false;
		print->space = false;
	}
	if (print->precision == true && ft_strchr("dioubxX", \
	print->output[print->i]))
		print->zero = false;
	if (print->minus == true)
		print->zero = false;
}

int		ft_shift(t_print *print)
{
	if (print->output[print->i] == 'q' || print->output[print->i] == 'n')
	{
		if (print->output[print->i] == 'q')
			print->roll_dice = true;
		else
			print->print_len = true;
		print->i++;
		return (0);
	}
	print->mod = field_width(print) + flag_pars_hash(print)\
	+ flag_pars_all(print)\
	+ modification_pars_h(print) + modification_pars_l(print) \
	+ precision_pars(print);
	while (!ft_strchr("dioufgbxXcsp%", print->output[print->i]))
		print->i++;
	if (print->output[print->i] == 0)
		return (0);
	excluser(print);
	return (1);
}
