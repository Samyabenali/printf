/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 15:21:45 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/17 13:02:14 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "libft.h"

int	len_count(intmax_t value, int base)
{
	int len;

	len = 0;
	if (value < 0)
	{	
		len = 1;
		value = value * -1;
	}
	while (value != 0)
	{
		value /= base;
		len++;
	}
	return (len);
}

char *ft_itoa_base(intmax_t value, int base)
{
	static  char rep[] = "0123456789abcdef";
	char		*ptr;
	char		*buff;
	intmax_t	 num;
	int			len;

	len = len_count(value, base);
	buff = malloc((len + 1) * sizeof(char));
	ptr = &buff[len];
	*ptr = '\0';
	num = value;
	if (value < 0 && base == 10)
		value = value * -1;
	if (value == 0)
		*--ptr = rep[0];
	while (value != 0)
	{
		*--ptr = rep[value % base];
		value = value / base;
	}
	if (num < 0 && base == 10)
		*--ptr = '-';
	return (ptr);
}
