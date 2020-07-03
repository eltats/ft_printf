/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:38:56 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/20 04:32:57 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_numbers_long(long long int nb)
{
	if (nb == LLONG_MIN)
		return (1 + ft_numbers_long(-223372036854775808));
	if (nb < 0)
		return (ft_numbers_long(nb * -1));
	if (nb >= 10)
		return (1 + ft_numbers_long(nb / 10));
	else
		return (1);
}

char	*ft_itoa_long(long long int n, t_print *print)
{
	char	*str;
	int		i;

	print->digit_zero = false;
	i = ft_numbers_long(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i--] = '\0';
	if (n == LLONG_MIN)
	{
		str[0] = '9';
		n = -223372036854775808;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		print->digit_zero = true;
		n = n * -1;
	}
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

int		ft_numbers_long_unsigned(unsigned long long int nb)
{
	if (nb >= 10)
		return (1 + ft_numbers_long_unsigned(nb / 10));
	else
		return (1);
}

char	*ft_itoa_long_unsigned(unsigned long long int n)
{
	char	*str;
	int		i;

	i = ft_numbers_long_unsigned(n);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
