/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_opt->bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:10:29 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/17 14:42:47 by sait-ben         ###   ########.fr       */
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

char	*apply_zero(char *res, t_options *opt)
{
	int		i;
	int		j;
	char 	*src;

	if (opt->moins == 1)
		return (res);
	if (ft_atoi_max(res) < 0)
	{
		if ((src = (char*)malloc(sizeof(char) * ft_strlen(res) + 1)) == NULL)
			return (NULL);
		src[0] = '-';
		i = 1;
		j = 0;
		while (res[j])
		{
			while (res[j] == ' ')
			{	
				src[i] = '0';
				i++;
				j++;
			}
			if (res[j] == '-')
			{	
				src[i] = '0';
				j++;
			}
			src[i] = res[j];
			i++;
			j++;
		}
		return (src);
	}
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
	if (opt->type == 'p' && (opt->zero == 1 && checkzerox(res) == 1))
	{
		src = ft_strdup(res);
		src[0] = '0';
		src[1] = 'x';
		i = 2;
		while (src[i] != 'x' && src[i])
			src[i++] = '0';
		src[i] = '0';
		return (src);
	}
	else
	{
		i = 0;
		while (res[i])
		{
			if (res[i] == ' ')
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

	(void)opt;
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
