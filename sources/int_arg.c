/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:07:22 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/08 12:18:38 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*int_arg(va_list ap, char c, t_options *opt)
{
	char		*res;
	uintmax_t	nb;
	intmax_t	nbb;
	int			resbis;

	if (ft_strchr("DOU", c) != NULL)
		res = dou_arg(ap, c, opt);
	if (opt->taille != 0 && ft_strchr("di", c) != NULL)
	{
		nbb = signed_cast(ap, opt);
//		if (nbb == -9223372036854775808)
//			return ("-9223372036854775808");
		return (ft_itoa_base(nbb, 10));
	}
	if (opt->taille != 0 && ft_strchr("ouxX", c) != NULL)
	{
		nb = unsigned_cast(ap, opt);
		if (c == 'o')
			return (ft_itoa_base_uint(nb, 8));
		if (c == 'u')
			return (ft_itoa_base_uint(nb, 10));
		return (ft_itoa_base_uint(nb, 16));
	}
	if (c == 'c')
	{
		resbis = va_arg(ap, int);
		res = (char*)malloc(sizeof(char) * 2);
		res[0] = (unsigned char)resbis;
		res[1] = '\0';
		return (res);
	}
	if (c == 'x')
		return (ft_itoa_base((va_arg(ap, unsigned int)), 16));
	if (c == 'X')
		return (ft_maj(ft_itoa_base((va_arg(ap, unsigned int)), 16)));
	if (c == 'o')
		return (ft_itoa_base(ft_valeurabsolue(va_arg(ap, int)), 8));
	if (c == 'u')
		return (ft_itoa_base(va_arg(ap,unsigned int), 10));
	res = ft_itoa_base(va_arg(ap, int), 10);
	return (res);
}
