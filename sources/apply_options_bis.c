/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 12:37:18 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/19 16:29:31 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		checkzero(char *str)
{
	int i;

	i = 0;
	while (str[i++])
	{
		if (str[i] != '0')
			return (0);
	}
	return (1);
}

int		checkzerox(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != 'x' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
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
	str = ft_strnew(ft_strlen(res) + 3);
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
			str[i++] = res[j++];
		str[i] = '\0';
	}
	free(res);
	return (str);
}

char	*apply_hashtag(char *res, t_options *opt)
{
	char	*str;
	int		i;
	int		j;

	if (ft_strchr("csdiupUCDS", opt->type) != NULL || opt->type == '%'
			|| ft_atoi(res) == 0)
		return (res);
	if (opt->type == 'o')
	{
		j = -1;
		i = 0;
		str = ft_strnew(ft_strlen(res) + 2);
		while (res[j++] == ' ')
			str[i++] = ' ';
		i--;
		if (res[j] == '0')
			return (res);
		str[i] = '0';
		i++;
		while (res[j])
			str[i++] = res[j++];
		str[i] = '\0';
		free(res);
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

	(void)opt;
	i = 0;
	j = 0;
	while (res[j] == ' ')
		j++;
	len = ft_strlen(res);
	str = ft_strnew(len + 1);
	while (res[j])
		str[i++] = res[j++];
	while (i < len)
		str[i++] = ' ';
	str[i] = '\0';
	free(res);
	return (str);
}
