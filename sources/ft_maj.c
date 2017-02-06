/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:43:18 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/06 13:44:13 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_maj(char *res)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * ft_strlen(res) + 1);
	if (str == NULL)
		return (res);
	while (res[i])
	{
		if (res[i] >= 97 && res[i] <= 122)
			str[i] = res[i] - 32;
		else
			str[i] = res[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
