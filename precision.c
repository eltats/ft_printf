/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:28:57 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/26 08:47:49 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_correct(char *res, char *str, t_print *print)
{
	char	*ret;

	res = (char *)malloc(sizeof(char) * \
	(print->precision_len - (int)ft_strlen(str) + 1));
	ft_memset(res, '0', print->precision_len - (int)ft_strlen(str));
	res[print->precision_len - (int)ft_strlen(str)] = '\0';
	ret = ft_strjoin(res, str);
	ft_strdel(&res);
	return (ret);
}

void	precision_true(t_print *print, int j, int wid)
{
	char	*atoi;

	atoi = NULL;
	j++;
	if (ft_isdigit(print->output[j]))
	{
		wid = j;
		while (ft_isdigit(print->output[wid]))
			wid++;
		atoi = ft_strsub(print->output, j, (size_t)wid - j);
		print->precision_len = ft_atoi(atoi);
		ft_strdel(&atoi);
	}
	print->precision = true;
}

int		precision_pars(t_print *print)
{
	int j;
	int	wid;

	wid = 0;
	j = print->i;
	print->precision = false;
	print->precision_len = 0;
	while (!ft_strchr("diofuqbxXs", print->output[j]))
	{
		if (print->output[j] == '.')
		{
			precision_true(print, j, wid);
			return (1);
		}
		j++;
	}
	return (0);
}
