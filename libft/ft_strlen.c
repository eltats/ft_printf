/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkraig <wkraig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:52:02 by wkraig            #+#    #+#             */
/*   Updated: 2020/02/29 01:00:45 by wkraig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned char	*str;
	size_t			len;

	str = (unsigned char *)s;
	len = 0;
	while (str[len])
		len++;
	return (len);
}
