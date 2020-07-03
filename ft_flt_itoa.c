/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flt_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 22:51:39 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/29 01:08:30 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_numss(long long int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_it_flt_l(long long int n, t_print *print)
{
	char	*str;
	int		i;

	i = ft_numss(n);
	n < 0 ? i-- : 0;
	str = (char *)ft_memalloc(sizeof(char) * (ft_numss(n) + 1));
	str[i--] = '\0';
	if (n == -2147483648)
	{
		str[1] = '2';
		n = -147483648;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		n *= -1;
		print->digit_zero = true;
	}
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
