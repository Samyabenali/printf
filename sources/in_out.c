/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:12:31 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/06 14:58:19 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		in_out(va_list ap, char c, t_options *opt)
{
	char	*str;
	int		len;

	init_flags(t_options *opt);
	str = parsing(ap, c, opt);
	str = apply_options(str, c, opt);
	len = ft_strlen(str);
	ft_putstr(str);
	return (len);
}
