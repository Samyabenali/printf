/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:38:22 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/17 11:46:42 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ulen_count(uintmax_t value, int base)
{
	int len;

	len = 0;
	while (value != 0)
	{
		value /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base_uint(uintmax_t value, int base)
{
	static char rep[] = "0123456789abcdef";
	char		*ptr;
	char		*buff;
	uintmax_t	num;
	int			len;

	len = ulen_count(value, base);
	buff = malloc((len + 1) * sizeof(char));
	ptr = &buff[len];
	*ptr = '\0';
	num = value;
	if (value == 0)
		*--ptr = rep[0];
	while (value != 0)
	{
		*--ptr = rep[value % base];
		value = value / base;
	}
	return (ptr);
}
