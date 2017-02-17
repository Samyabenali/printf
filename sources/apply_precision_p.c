/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:37:51 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/16 18:19:02 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_precision_p(char	*str, t_options *opt)
{
	char	*src;
	int		i;
	int		j;
	
	if ((src = (char*)malloc(sizeof(char) * (3 + opt->precision))) == NULL)
		return (NULL);
	src[0] = '0';
	src[1] = 'x';
	i = 2;
	if (checkzerox(str) == 1)
	{	
		while (i < opt->precision + 2)
			src[i++] = '0';
	}
	else
	{
		while (i < (opt->precision + 4) - (int)ft_strlen(str))
			src[i++] = '0';
		j = 2;
		while (str[j])
			src[i++] = str[j++];
	}
	src[i] = '\0';
	return (src);
}

char	*applyZ(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i--;
	str[i] = 'Z';
	return (str);
}
