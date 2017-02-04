/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:12:31 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/03 17:38:43 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		in_out(va_list ap, char *str, t_options *opt)
{
	init_flags(t_options *opt);
	str = convert(ap, str, opt);
	str = apply_options(ap, str, opt);
	opt->buffer = ft_strcat(opt->buffer, str);
	return (len);
}
