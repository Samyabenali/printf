/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:10:59 by sait-ben          #+#    #+#             */
/*   Updated: 2017/01/04 17:01:46 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	myprintf(char *str, ...)
{
	int	i;
	va_list ap;
	va_start(ap, str);
	t_options opt;
	int	len;

	i = 0;
	if (str[i] == '%')
	{
		len = parsing(ap, str[i + 1], &opt);
		ft_putstr(opt.buff);
//		option_detect(str[i], &opt);
		i = i + len;
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
