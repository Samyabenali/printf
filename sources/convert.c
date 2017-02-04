/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:11:02 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/03 17:10:35 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		parsing(va_list ap, char c, t_options *opt)
{
	int i;	
	static const t_flags g_conv[] = {
//		{ "bdiouxX", &int_arg },
//		{ "DOU", &dou_arg },
//		{ "Cc", &c_arg },
		{ "s", &s_arg },
//		{ "S", &ws_arg },
//		{ "p", &p_arg },
//		{ "%", &pct_arg }
	};

	i = 0;
	while (i != 6)
	{
		if (ft_strchr(g_conv[i].str, c) != 0)
		{	
		//	ft_putstr("rentre");
			return (g_conv[i].f(ap, c, opt));
		}
		i++;
	}
	return (0);
}

int		option_detect(char *str, int i, t_options *opt)
{
	if (c == '-')
		opt->left_align = 1;
	if (c == '+')
		opt->positiv = 1;
	if (c == '#')
		opt->hashtag = 1;
	if (c == '0')
		opt->zero = 1;
	if (c == ' ')
		opt->space = 1;
	i++;
	return (i);
}
