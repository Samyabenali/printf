/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:23:43 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/08 12:29:54 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*p_arg(va_list ap, char c, t_options *opt)
{
	char	*res;
	char	*str;
	int		i;
	int		len;

	(void)opt;
	if (c)
	{
		str = ft_itoa_base((intmax_t)va_arg(ap, void*), 16);
		len = ft_strlen(str);
		res = (char*)malloc(sizeof(char) * len + 3);
		i = 2;
		res[0] = '0';
		res[1] = 'x';
		res[len + 2] = '\0';
		while (i < len + 2)
		{
			res[i] = str[i - 2];
			i++;
		}
	}
	else
		res = NULL;
	return (res);
}
