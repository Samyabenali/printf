/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:10:59 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/14 13:58:52 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(char *str, ...)
{
	int			i;
	va_list		ap;
	t_options	opt;
	int			len;

	len = 0;
	i = 0;
	va_start(ap, str);
	init_flags(&opt);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break;
			while (ft_strchr(" .0123456789+-#lhzj", str[i]) != NULL && str[i] != '\0')
				i = option_detect(str, i, &opt);
			if (str[i] && ft_strchr("diouxXcCDOUsSp%ZR", str[i]) != NULL)
			{	
				len += in_out(ap, str[i], &opt);
				i++;
			}
			else if (ft_strchr("diouxXcCDOUsSp", str[i]) == NULL)
			{
				ft_putchar(str[i]);
				len++;
				i++;
			}
		}
		else
		{
			ft_putchar(str[i]);
			i++;
			len++;
		}
	}
	va_end(ap);
	return (len);
}
