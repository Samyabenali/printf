/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_opt->bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:10:29 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/06 16:17:57 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_zero(char *res, t_options *opt)
{
	int		i;

	if (opt->moins == 1)
		return (res);
	if ((opt->type == 'x' || opt->type == 'X') && opt->hashtag == 1)
	{
		res[0] = '0';
		res[1] = opt->type;
		i = 2;
		while (res[i] != opt->type)
		{
			res[i] = '0';
			i++;
		}
		res[i] = '0';
		return (res);
	}
	i = 0;
	if (opt->plus == 1 && ft_atoi(res) > 0)
		i = 1;
	if (ft_atoi(res) < 0)
	{
		res[i] = '-';
		i++;
		while (res[i] < 48 || res[i] > 57)
		{
			res[i] = '0';
			i++;
		}
	}
	else
	{
		while (res[i] == ' ')
		{
			res[i] = '0';
			i++;
		}
	}
	return (res);
}

char	*apply_hashtag_x(char *res, t_options *opt)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_atoi(res) == 0)
		return (res);
	str = (char*)malloc(sizeof(char) * ft_strlen(res) + 3);
	while (res[j])
	{
		str[i] = '0';
		i++;
		if (opt->type == 'X')
			str[i] = 'X';
		if (opt->type == 'x')
			str[i] = 'x';
		i++;
		while (res[j])
		{
			str[i] = res[j];
			i++;
			j++;
		}
		str[i] = '\0';
	}
	return (str);
}

char	*apply_hashtag(char *res, t_options *opt)
{
	char	*str;
	int		i;
	int		j;

	if (ft_strchr("csdiupUCDS", opt->type) != NULL || opt->type == '%' || ft_atoi(res) == 0)
		return (res);
	if (opt->type == 'o')
	{
		j = 0;
		i = 0;
		str = (char*)malloc(sizeof(char) * ft_strlen(res) + 2);
		while (res[j] == ' ')
		{
			j++;
			str[i] = ' ';
			i++;
		}
		i--;
		if (res[j] == '0')
		{
			free(str);
			return (res);
		}
		str[i] = '0';
		i++;
		while (res[j])
		{
			str[i] = res[j];
			i++;
			j++;
		}
		return (str);
	}
	return (res);
}

char	*apply_moins(char *res, t_options *opt)
{
	int		i;
	int		j;
	char	*str;
	int		len;

	i = 0;
	j = 0;
	while (res[j] == ' ')
		j++;
	len = ft_strlen(res);
	str = (char*)malloc(sizeof(char) * len + 1);
	while (res[j])
	{
		str[i] = res[j];
		i++;
		j++;
	}
	while (i < len)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}
