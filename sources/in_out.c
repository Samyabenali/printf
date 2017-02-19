/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:12:31 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/19 16:28:37 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		in_out(va_list ap, char c, t_options *opt)
{
	char	*str;
	int		len;

	opt->type = c;
	str = parsing(ap, c, opt);
	if (c == 'p' && opt->precision >= (int)ft_strlen(str))
		str = apply_precision_p(str, opt);
	else
		str = apply_options(str, c, opt);
	if (opt->type == 'Z' && opt->precision != -1)
		str = apply_z(str);
	ft_putstr(str);
	len = ft_strlen(str);
	if ((c == 'c' && len == 0) || opt->slen == 1)
	{
		ft_putchar('\0');
		init_flags(opt);
		return (len + 1);
	}
	init_flags(opt);
	return (len);
}
