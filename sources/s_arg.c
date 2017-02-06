/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:46:46 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/06 17:16:43 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*s_arg(va_list ap, char c, t_options *opt)
{
	char	*str;
	
	if (opt->taille == 3)
		str = va_arg(ap, char*);
	else
		str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	return (str);
}
