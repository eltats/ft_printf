/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:28:54 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/29 01:08:57 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		field_width(t_print *print)
{
	int		j;
	int		wid;
	char	*atoi;

	j = print->i;
	print->width = 0;
	atoi = NULL;
	while (!ft_strchr("dioufbxXcsp%.", print->output[j]))
	{
		if (ft_isdigit(print->output[j]) && print->output[j - 1] != '.' \
		&& print->output[j] != '0')
		{
			wid = j;
			while (ft_isdigit(print->output[wid]))
				wid++;
			atoi = ft_strsub(print->output, j, (size_t)wid - j);
			print->width = ft_atoi(atoi);
			ft_strdel(&atoi);
			return (1);
		}
		j++;
	}
	return (0);
}

void	ft_true_wid(t_width *wid, bool *enter, int spec, t_print *print)
{
	if (ft_isdigit(wid->str[0]))
		wid->filler == '0' ? ft_modflags(print, enter) : 0;
	wid->width_len = spec + wid->hate_printf + wid->plus + wid->zeroplus + \
	wid->hash + print->width - (int)ft_strlen(wid->str);
	if (print->output[print->i] == 'c')
		(int)ft_strlen(wid->str) == 0 ? wid->width_len -= 1 : 0;
	if (ft_isdigit(wid->str[0]) && print->digit_zero == true && \
	print->precision == true && print->plus == false && print->space \
	== false && wid->zeroplus != -1)
		wid->width_len -= 1;
	wid->width = (char *)malloc(sizeof(char) * (wid->width_len + 1));
	ft_memset(wid->width, wid->filler, wid->width_len);
	wid->width[wid->width_len] = '\0';
	write(print->fd, wid->width, ft_strlen(wid->width));
	print->return_value += (int)ft_strlen(wid->width);
	free(wid->width);
}

void	ft_val_width(t_print *print, t_width *wid, char *str)
{
	if (str[0] == '0')
		if (print->plus == true || print->space == true)
			wid->plus = -1;
	print->zero == true ? wid->filler = '0' : 0;
	if (str[0] != '0')
		ft_hashflags(print, wid);
	if (!wid->hash)
	{
		if (print->hash == true && print->output[print->i] != 'f')
			wid->hate_printf += -2;
	}
}

void	ft_width(t_print *print, char *str, bool *enter, int spec)
{
	t_width		*wid;

	wid = (t_width *)ft_memalloc(sizeof(t_width));
	ft_bzero(wid, sizeof(t_width));
	wid->filler = ' ';
	wid->str = str;
	ft_val_width(print, wid, wid->str);
	if ((spec + wid->hate_printf + wid->plus + wid->zeroplus + wid->hash + \
	print->width - (int)ft_strlen(wid->str)) > 0)
	{
		ft_true_wid(wid, enter, spec, print);
		if ((wid->filler == ' ' && (print->output[print->i] == 'x' || \
		print->output[print->i] == 'X') && print->hash == true && \
		wid->str[0] != '0'))
		{
			print->output[print->i] == 'x' ? write(print->fd, "0x", 2)\
			: write(print->fd, "0X", 2);
			print->return_value += 2;
			print->hash = false;
		}
		if (ft_isdigit(wid->str[0]))
			wid->filler == ' ' ? ft_modflags(print, enter) : 0;
	}
	free(wid);
}
