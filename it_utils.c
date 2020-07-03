/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:51:30 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/29 01:09:10 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_itoa_helper16(unsigned long long int base)
{
	int i;

	i = 0;
	while (base /= 16 != 0)
	{
		i++;
		base /= 16;
	}
	return (i);
}

char	*ft_capitalize(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = str;
	while (res[i])
	{
		if (ft_isalpha(res[i]))
			res[i] -= 32;
		i++;
	}
	return (res);
}

int		ft_itoa_helper_unsigned(unsigned long long int n, \
unsigned long long int base)
{
	int i;

	i = 0;
	while (n /= base != 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

char	*n_null_pred(char *res, t_print *print)
{
	if (print->hash == true)
		print->hash = false;
	else
	{
		print->hash = false;
		print->octal = true;
	}
	res = (char *)malloc(sizeof(char) * (2));
	res[0] = '0';
	res[1] = '\0';
	return (res);
}
