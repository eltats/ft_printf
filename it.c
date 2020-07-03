/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:39:02 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/29 01:07:35 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_xflag(unsigned long long int n, \
unsigned long long int base, t_print *print)
{
	static char		*sh = "0123456789abcdef";
	char			*res;
	int				i;

	if (n == 0)
	{
		print->hash = false;
		res = (char *)malloc(sizeof(char) * (2));
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	i = ft_itoa_helper16(n);
	res = (char *)malloc(sizeof(char) * (i + 1));
	res[i--] = '\0';
	while (n != 0)
	{
		res[i] = sh[n % base];
		i--;
		n /= base;
	}
	if (print->output[print->i] == 'X')
		res = ft_capitalize(res);
	return (res);
}

char	*res_init(char *res)
{
	res = (char *)malloc(sizeof(char) * (4));
	res[0] = '0';
	res[1] = 'x';
	res[2] = '0';
	res[3] = '\0';
	return (res);
}

void	ft_itoa_base_16(unsigned long long int n, \
unsigned long long int base, t_print *print)
{
	static char	sh[] = "0123456789abcdef";
	char		*res;
	int			i;

	res = NULL;
	if (n == 0)
	{
		res = res_init(res);
		return (ft_mainout(print, res));
	}
	i = ft_itoa_helper16(n);
	res = (char *)malloc(sizeof(char) * (i + 3));
	i += 2;
	res[i--] = '\0';
	while (n != 0)
	{
		res[i] = sh[n % base];
		i--;
		n /= base;
	}
	res[i--] = 'x';
	res[i] = '0';
	ft_mainout(print, res);
}

char	*ft_itoa_base_unsigned(unsigned long long int n, \
unsigned long long int base, t_print *print)
{
	int		i;
	char	*res;

	res = NULL;
	if (n == 0)
		return (n_null_pred(res, print));
	i = ft_itoa_helper_unsigned(n, base);
	if (print->hash == true)
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	res[i--] = '\0';
	while (n != 0)
	{
		res[i] = (n % base) + '0';
		n /= base;
		i--;
	}
	if (print->hash == true)
	{
		print->hash = false;
		res[i] = '0';
	}
	return (res);
}
