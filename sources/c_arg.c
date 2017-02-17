/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:48:07 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/15 18:42:14 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*c_arg(va_list ap, char c, t_options *opt)
{
	char	*str;
	char	w;
	wchar_t	wt;

	(void)opt;
	str = NULL;
	if (c == 'c' && opt->taille == 0)
	{
		w = va_arg(ap, int);
		if ((str = (char*)malloc(sizeof(char)* 2)) == NULL)
				return (NULL);
		str[0] = (unsigned char)w;
		str[1] = '\0';
		return (str);
	}
	if (c == 'c' && opt->taille != 0)
	{
		wt = va_arg(ap, wchar_t);
		str = ft_wputchar(wt);
	}
	if (opt->type == 'C')
	{	
		wt = va_arg(ap, wchar_t);
		if (wt == 0)
			opt->slen = 1;
		str = ft_wputchar(wt);
	}
	return (str);
}
