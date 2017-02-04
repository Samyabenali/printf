/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:10:59 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/03 18:05:31 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(char *str, ...)
{
	int		i;
	int 	j;
	va_list	ap;
	t_options opt;
	int	len;

	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		opt.buffer[i++] = str[j++];
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

	}
	opt.buff[i] = '\0';
//	ft_putstr(opt.buff);
}		


int		main()
{
	myprintf("%s", "paul");
	ft_putchar('\n');
//	printf("Ton nom est : %", "paul");
	return (0);
}
