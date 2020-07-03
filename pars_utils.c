/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:33:18 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/28 21:34:39 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fd(t_print *print, void *res)
{
	if (print->output[print->i] == 'g')
		print->fd = (int)res;
	else
		print->fd = 2;
}

int		ft_fl_len(long double flt)
{
	int		i;

	i = 0;
	while (flt / 10)
	{
		i++;
		flt /= 10;
	}
	return (i);
}
