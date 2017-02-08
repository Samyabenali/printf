/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:12:31 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/08 16:54:40 by sait-ben         ###   ########.fr       */
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
/*	printf("moins = %d\n", opt->moins);
	printf("plus = %d\n", opt->plus);
	printf("zero = %d\n", opt->zero);
	printf("space = %d\n", opt->space);
	printf("precision = %d\n", opt->precision);
	printf("largeur = %d\n", opt->largeur);
	printf("taille = %d\n", opt->taille);
	printf("type = %c\n", opt->type);
*/	str = apply_options(str, c, opt);
	ft_putstr(str);
	init_flags(opt);
	return (ft_strlen(str));
}
