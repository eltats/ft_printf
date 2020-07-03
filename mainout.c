/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:28:45 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/25 18:07:35 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_main_wid(t_print *print, char *str, bool *enter)
{
	ft_wid_out(print, str, enter);
	if (str != print->out)
		free(print->out);
	if (print->output[print->i] != 's')
		free(str);
}

void	ft_main_wid_min(t_print *print, char *str, bool *enter)
{
	print->out = ft_digit_crips(print, str);
	ft_width(print, print->out, enter, print->spec);
}

void	ft_mainout(t_print *print, char *str)
{
	static bool	enter;

	enter = false;
	print->spec = 0;
	if (str == NULL)
		return (ft_null_out(print, &enter));
	if (print->width && print->minus == false)
		ft_main_wid_min(print, str, &enter);
	else if (print->width)
		return (ft_main_wid(print, str, &enter));
	else
		print->out = ft_digit_crips(print, str);
	if (ft_isdigit(str[0]))
		ft_modflags(print, &enter);
	if ((print->output[print->i] == 'x' || print->output[print->i] == 'X') \
	&& print->hash == true && str[0] != '0')
		ft_out_x(print);
	if (write(print->fd, print->out, ft_strlen(print->out)))
		print->return_value += (int)ft_strlen(print->out);
	if ((print->need_free == true && print->output[print->i] == 's')\
	|| print->output[print->i] != 's')
		free(print->out);
	if (print->output[print->i] != 's' && ((!print->width && print->out \
	!= str) || print->out != str))
		free(str);
}

int		ft_check(t_print *print)
{
	int	i;

	i = print->i;
	while (print->output[i] != '%')
	{
		if (ft_strchr("csp", print->output[i]))
			return (0);
		i++;
	}
	return (1);
}
