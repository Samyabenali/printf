/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:50:47 by sait-ben          #+#    #+#             */
/*   Updated: 2017/01/02 17:03:10 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		len_count(int nb)
{
	int len;
	
	len = 0;
	if (nb < 10)
	{	
		len = 1;
		nb = nb * -1;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return(len);
}

char	*ft_itoa(int nb)
{
	char rep[] = "0123456789";
	char *buff;
	char *ptr;
	unsigned int num;
	int len;

	len = len_count(nb);
	buff = malloc(sizeof(char) * (len + 1));
	ptr = &buff[len];
	*ptr = '\0';
	num = nb;
	if (nb < 0)
		num = nb * -1;
	if (num == 0)
		*--ptr = rep[0];
	while (num != 0)
	{
		*--ptr = rep[num % 10];
		num = num / 10;
	}
	if (nb < 0)
		*--ptr = '-';
	return (ptr);
}

int	main()
{
	char *str;

	str = ft_itoa(-2147483647);
	printf("%s\n", str);
	return (0);
}
