/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 17:29:01 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/25 18:06:19 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_digit_if(t_print *print, char *str, char *res, char *kv)
{
	if ((int)ft_strlen(str) < print->precision_len)
		return (ft_precision_correct(res, str, print));
	else if (print->output[print->i] == 'o' && ft_atoi(str) == 0 && \
	print->octal == false)
		return (str);
	else if (str[0] == '0' && !str[1] && ft_strchr("diuoxX", \
	print->output[print->i]) && print->hash == false)
		return (ft_kv(kv));
	return (str);
}

char	*ft_digit_crips(t_print *print, char *str)
{
	char	*res;
	char	*kv;

	res = NULL;
	kv = NULL;
	print->need_free = false;
	if (print->precision == true)
	{
		if (ft_strchr("dioubxX", print->output[print->i]))
			return (ft_digit_if(print, str, res, kv));
		else if (print->output[print->i] == 's' && (int)ft_strlen(str) > \
		print->precision_len)
		{
			print->need_free = true;
			return (ft_strsub(str, 0, print->precision_len));
		}
	}
	print->precision = false;
	return (str);
}

void	ft_null_out(t_print *print, bool *enter)
{
	char	*null;

	null = (char *)malloc(sizeof(char) * (7));
	ft_fill(null);
	if (print->width && print->minus == false)
	{
		print->out = ft_digit_crips(print, null);
		ft_width(print, print->out, enter, print->spec);
		write(print->fd, print->out, ft_strlen(print->out));
	}
	else if (print->width)
	{
		print->out = ft_digit_crips(print, null);
		write(print->fd, print->out, ft_strlen(print->out));
		ft_width(print, print->out, enter, print->spec);
	}
	else
	{
		print->out = ft_digit_crips(print, null);
		write(print->fd, print->out, ft_strlen(print->out));
	}
	print->return_value += (int)ft_strlen(print->out);
	free(print->out);
}

void	ft_wid_out(t_print *print, char *str, bool *enter)
{
	ft_modflags(print, enter);
	if ((print->output[print->i] == 'x' || print->output[print->i] == 'X') \
	&& print->hash == true && str[0] != '0')
	{
		if (print->output[print->i] == 'x')
			write(print->fd, "0x", 2);
		else
			write(print->fd, "0X", 2);
		print->return_value += 2;
		print->hash = false;
		print->spec = -2;
	}
	print->out = ft_digit_crips(print, str);
	write(print->fd, print->out, ft_strlen(print->out));
	print->return_value += (int)ft_strlen(print->out);
	return (ft_width(print, print->out, enter, print->spec));
}

void	ft_p_out(t_print *print)
{
	char	*pr;

	pr = (char *)ft_memalloc(sizeof(char) * (2));
	pr[0] = '%';
	pr[1] = '\0';
	ft_mainout(print, pr);
}
