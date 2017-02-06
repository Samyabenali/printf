/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:10:59 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/06 17:37:17 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(char *str, ...)
{
	int			i;
	va_list		ap;
	t_options	opt;
	int			len;

	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (ft_strchr("diouxXDOUsSp%", str[i]) == NULL)
				i += option_detect(str, i, &opt);
			if (ft_strchr("diouxXDOUsSp%", str[i]) != NULL)
			{	
				len += in_out(ap, str[i], &opt);
				i++;
			}
		}
		ft_putchar(str[i]);
		i++;
	}
	return (len);
}		
