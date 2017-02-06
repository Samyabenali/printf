/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:48:07 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/06 15:57:14 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*c_arg(va_list ap, char c, t_options *opt)
{
	char	*str;
	wchar_t	wt;

	if (c == 'c')
	{
		if ((str = (char*)malloc(sizeof(char)* 2)) == NULL)
				return (NULL);
		str[0] = c;
		str[1] = '\0';
	}
	if (c == 'C')
		wt = va_arg(ap, wchar_t);
		str = ft_wputchar(wt);
	return (str);
}
