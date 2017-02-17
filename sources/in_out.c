/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:12:31 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/17 13:02:31 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		in_out(va_list ap, char c, t_options *opt)
{
	char	*str;
	int		len;

	len = 0;
	opt->type = c;
	str = parsing(ap, c, opt);
	if (c == 'p' &&  opt->precision >= (int)ft_strlen(str))
		str = apply_precision_p(str, opt);
	else
		str = apply_options(str, c, opt);
	if (opt->type == 'Z' && opt->precision != -1)
		str = applyZ(str);
	ft_putstr(str);
	if ((c == 'c' && ft_strlen(str) == 0) || opt->slen == 1)
	{	
		ft_putchar('\0');
		init_flags(opt);
		return (ft_strlen(str) + 1);
	}
	init_flags(opt);
	return (ft_strlen(str));
}
