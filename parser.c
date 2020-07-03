/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:28:51 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/28 22:45:10 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		modification_pars_h(t_print *print)
{
	int j;

	j = print->i;
	print->h = false;
	print->hh = false;
	while (!ft_strchr("dioubxX", print->output[j]))
	{
		if (print->output[j] == 'h')
		{
			if (print->output[j + 1] == 'h')
				print->hh = true;
			else
				print->h = true;
			return (1);
		}
		j++;
	}
	return (0);
}

int		modification_pars_l(t_print *print)
{
	int j;

	j = print->i;
	print->l = false;
	print->ll = false;
	print->big_l = false;
	while (!ft_strchr("diofubxX", print->output[j]))
	{
		if (print->output[j] == 'l' || print->output[j] == 'L')
		{
			if (print->output[j] == 'L')
				print->big_l = true;
			if (print->output[j + 1] == 'l')
				print->ll = true;
			else
				print->l = true;
			return (1);
		}
		j++;
	}
	return (0);
}

void	ft_stdout_binary(t_print *print, void *res)
{
	char	*str;

	if (print->h == true)
		str = ft_itoa_base_unsigned((unsigned short int)res, 2, print);
	else if (print->hh == true)
		str = ft_itoa_base_unsigned((unsigned char)res, 2, print);
	else if (print->l == true)
		str = ft_itoa_base_unsigned((unsigned long int)res, 2, print);
	else if (print->ll == true)
		str = ft_itoa_base_unsigned((unsigned long long int)res, 2, print);
	else
		str = ft_itoa_base_unsigned((unsigned int)res, 2, print);
	ft_mainout(print, str);
}

int		pars_norm(t_print *print, void *res)
{
	if (print->output[print->i] == 'd' || print->output[print->i] == 'i')
		ft_stdout_digits(print, res);
	else if (print->output[print->i] == 's')
		ft_mainout(print, (char *)res);
	else if (print->output[print->i] == 'p')
		ft_itoa_base_16((unsigned long long int)res, 16, print);
	else if (print->output[print->i] == 'c')
		ft_charout(print, res);
	else if (print->output[print->i] == 'u')
		ft_stdout_unsignedint(print, res);
	else if (print->output[print->i] == 'x' || print->output[print->i] == 'X')
		ft_stdout_hex(print, res);
	else if (print->output[print->i] == 'o')
		ft_stdout_octal(print, res);
	else if (print->output[print->i] == 'b')
		ft_stdout_binary(print, res);
	else if (print->output[print->i] == 'g' || print->output[print->i] == 'e')
		ft_fd(print, res);
	else if (print->output[print->i] == 'f')
		ft_float(print);
	else
		return (0);
	return (1);
}

void	parser(t_print *print)
{
	void	*res;

	print->digit_zero = false;
	print->precision_len = 0;
	res = NULL;
	if (!(ft_shift(print)))
		return ;
	if (print->output[print->i] != 'f')
		print->output[print->i] != '%' ? res = va_arg(print->argp, void *)\
		: ft_p_out(print);
	if (!(pars_norm(print, res)))
	{
		print->i++;
		return ;
	}
	else
		print->i++;
}
