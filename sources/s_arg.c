/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:46:46 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/08 17:30:14 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*s_arg(va_list ap, char c, t_options *opt)
{
	char	*str;
	
	(void)opt;
	(void)c;
	str = va_arg(ap, char*);
	if (str == NULL)
		str = ("");
	return (str);
}
