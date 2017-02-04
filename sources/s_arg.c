/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:46:46 by sait-ben          #+#    #+#             */
/*   Updated: 2017/01/04 17:01:09 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		s_arg(va_list ap, char c, t_options *opt)
{
	char *str;
	
	str = va_arg(ap, char*);
	ft_strcat(opt->buff, str);
	return (ft_strlen(str));
}
