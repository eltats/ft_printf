/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:27:11 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/29 01:01:04 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_stdout_digits(t_print *print, void *res)
{
	char	*str;

	str = NULL;
	if (print->h == true)
		str = ft_itoa_long((short)res, print);
	else if (print->hh == true)
		str = ft_itoa_long((char)res, print);
	else if (print->l == true)
		str = ft_itoa_long((long int)res, print);
	else if (print->ll == true)
		str = ft_itoa_long((long long int)res, print);
	else
		str = ft_itoa_long((int)res, print);
	ft_mainout(print, str);
}

void	ft_stdout_octal(t_print *print, void *res)
{
	char	*str;

	str = NULL;
	print->octal = false;
	if (print->h == true)
		str = ft_itoa_base_unsigned((unsigned short int)res, 8, print);
	else if (print->hh == true)
		str = ft_itoa_base_unsigned((unsigned char)res, 8, print);
	else if (print->l == true)
		str = ft_itoa_base_unsigned((unsigned long int)res, 8, print);
	else if (print->ll == true)
		str = ft_itoa_base_unsigned((unsigned long long int)res, 8, print);
	else
		str = ft_itoa_base_unsigned((unsigned int)res, 8, print);
	ft_mainout(print, str);
}

void	ft_stdout_unsignedint(t_print *print, void *res)
{
	char	*str;

	str = NULL;
	if (print->h == true)
		str = ft_itoa_long_unsigned((unsigned short)res);
	else if (print->hh == true)
		str = ft_itoa_long_unsigned((unsigned char)res);
	else if (print->l == true)
		str = ft_itoa_long_unsigned((unsigned long int)res);
	else if (print->ll == true)
		str = ft_itoa_long_unsigned((unsigned long long int)res);
	else
		str = ft_itoa_long_unsigned((unsigned int)res);
	ft_mainout(print, str);
}

void	ft_stdout_hex(t_print *print, void *res)
{
	char	*str;

	str = NULL;
	if (print->h == true)
		str = ft_xflag((unsigned short int)res, 16, print);
	else if (print->hh == true)
		str = ft_xflag((unsigned char)res, 16, print);
	else if (print->l == true)
		str = ft_xflag((unsigned long int)res, 16, print);
	else if (print->ll == true)
		str = ft_xflag((unsigned long long int)res, 16, print);
	else
		str = ft_xflag((unsigned int)res, 16, print);
	ft_mainout(print, str);
}

void	ft_charout(t_print *print, void *res)
{
	short int	c;
	char		*wid;
	int			wid_len;

	c = (short int)res;
	if (print->width)
	{
		wid_len = print->width - 1;
		if (print->minus == true)
		{
			write(print->fd, &c, 1);
			print->return_value += 1;
		}
		if (wid_len)
		{
			wid = (char *)ft_memalloc(sizeof(char) * (wid_len + 1));
			ft_memset(wid, ' ', wid_len);
			wid[wid_len] = '\0';
			write(print->fd, wid, ft_strlen(wid));
			print->return_value += ft_strlen(wid);
			free(wid);
		}
	}
	if (print->minus == false)
		ft_min_in_char(print, c);
}
