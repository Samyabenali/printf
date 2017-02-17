/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:07:22 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/17 12:14:15 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*oh_arg(va_list ap, uintmax_t nb, t_options *opt)
{
	int			i;
	int			j;
	char		*str;
	char		*res;

	(void)opt;
	(void)ap;
	i = 0;
	j = 0;
	res = ft_itoa_base_uint(nb, 8);
	str = ft_strnew(ft_strlen(res + 2));
	str[0] = '0';
	i++;
	while (res[j])
		str[i++] = res[j++];
	str[i] = '\0';
	return (str);
}

char	*o_arg(va_list ap, char c, t_options *opt)
{
	int			i;
	int			j;
	uintmax_t 	k;
	char		*str;
	char		*res;

	k = va_arg(ap, unsigned int);
	if (c == 'o' && opt->hashtag == 1 && k != 0)
	{	
		i = 0;
		j = 0;
		res = ft_itoa_base(k, 8);
		str = ft_strnew(ft_strlen(res + 2));
		str[0] = '0';
		i++;
		while (res[j])
			str[i++] = res[j++];
		str[i] = '\0';
		return (str);
	}
	else
		return (ft_itoa_base_uint(ft_valeurabsolue(k), 8));
}

char	*int_arg(va_list ap, char c, t_options *opt)
{
	char		*res;
	uintmax_t	nb;
	intmax_t	nbb;
	
	if (opt->taille != 0 && ft_strchr("di", c) != NULL)
	{
		nbb = signed_cast(ap, opt);
		if (nbb == -9223372036854775807 - 1)
			return ("-9223372036854775808");
		return (ft_itoa_base(nbb, 10));
	}
	if (opt->taille != 0 && ft_strchr("ouxX", c) != NULL)
	{
		nb = unsigned_cast(ap, opt);
		if (c == 'o' && opt->hashtag == 0)
			return (ft_itoa_base_uint(nb, 8));
		if (c == 'o' && opt->hashtag == 1)
			return (oh_arg(ap, nb, opt));
		if (c == 'u')
			return (ft_itoa_base_uint(nb, 10));
		if (c == 'X')
			return (ft_maj(ft_itoa_base_uint(nb, 16)));
		return (ft_itoa_base_uint(nb, 16));
	}
	if (c == 'o' && opt->taille == 0)
		return (o_arg(ap, c, opt));
	if (c == 'x')
		return (ft_itoa_base((va_arg(ap, unsigned int)), 16));
	if (c == 'X')
		return (ft_maj(ft_itoa_base((va_arg(ap, unsigned int)), 16)));
	if (c == 'u' && opt->taille == 0)
		return (ft_itoa_base(va_arg(ap,unsigned int), 10));
	res = ft_itoa_base(va_arg(ap, int), 10);
	return (res);
}
