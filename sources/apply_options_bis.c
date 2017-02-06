/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:53:46 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/06 12:05:56 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_options_bis(char *str, t_options *opt)
{
	int		len;
	char	*src;
	int		index;

	index = 0;
	src = (char*)malloc(sizeof(char) * opt->precision + 1);
	if (src == NULL)
		return (NULL);
	while (str[index] == ' ')
		index++;
	while (i <= (opt->precision - ft_strlen(res) + index))
	{
		src[index] = '0';
		i++;
		index++;
	}
	return (src);
}
