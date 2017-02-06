/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:50:21 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/06 14:53:37 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*pct_arg(va_list ap, char c, t_options *opt)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * 2);
	res[0] = '%';
	res[1] = '\0';
	if (c)
		va_arg(ap, intmax_t);
	return (res);
}
