/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_opt->c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:24:27 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/06 14:48:53 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_largeur(char *str, t_options *opt)
{
	char	*src;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((int)ft_strlen(str) >= opt->largeur)
		return (str);
	else
	{
		src = (char*)malloc(sizeof(char) * opt->largeur + 1);
		while (i < (opt->largeur - (int)ft_strlen(str)))
		{
			src[i] = ' ';
			i++;
		}
		while (j < (int)ft_strlen(str))
		{
			src[i] = str[j];
			i++;
			j++;
		}
	}
	src[i] = '\0';
	return (src);
}

char	*apply_precision_neg(char *str, t_options *opt)
{
	int		i;
	int		j;
	char	*src;

	src = (char*)malloc(sizeof(char) * opt->precision + 2);
	i = 1;
	j = 1;
	src[0] = '-';
	src[opt->precision + 1] = '\0';
	while (str[j])
	{
		while (i <= (opt->precision - (int)ft_strlen(str) + 1))
		{
			src[i] = '0';
			i++;
		}
		while (str[j])
		{
			src[i] = str[j];
			i++;
			j++;
		}
		opt->zero = 0;
	}
	return (src);
}

char	*apply_precision(char *str, t_options *opt)
{
	int		i;
	int		j;
	char	*src;
	int		len;

	i = 0;
	j = 0;
	len = (int)ft_strlen(str);
	if (opt->precision == 0 && ft_atoi(str) == 0)
	{
		str = (char*)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	if (len >= opt->precision && c == 's')
		return (ft_strsub(str, 0, opt->precision));
	if ((int)ft_strlen(str) >= opt->precision)
		return (str);
	else
	{
		len = 0;
		if (ft_atoi(str) < 0)
			return (apply_precision_neg(opt-> str));
		src = (char*)malloc(sizeof(char) * opt->precision + 1);
		while (i < (opt->precision - (int)ft_strlen(str)))
		{
			src[i] = '0';
			i++;
		}
		src[opt->precision] = '\0';
		while (str[j])
		{
			src[i] = str[j];
			i++;
			j++;
		}
		opt->zero = 0;
	}
	return (src);
}

char	*apply_plus(char *str, t_options *opt)
{
	int		i;
	char	*src;

	i = 0;
	if (ft_atoi(str) < 0 || ft_strchr("di", c) == NULL)
		return (str);
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
		i--;
		str[i] = '+';
		return (str);
	}
	else
		src = (char*)malloc(sizeof(char) * ft_strlen(str) + 2);
	src[i] = '+';
	i++;
	src[ft_strlen(str) + 1] = '\0';
	while (i <= (int)ft_strlen(str))
	{
		src[i] = str[i - 1];
		i++;
	}
	return (src);
}

char	*apply_space(char *str, t_options *opt)
{
	int		i;
	char	*src;
	int		len;

	i = 0;
	if (ft_atoi(str) < 0 || opt->plus == 1 || str[i] == ' ' || ft_strchr("di", c) == NULL)
		return (str);
	else
	{
		len = ft_strlen(str) + 2;
		src = (char*)malloc(sizeof(char) * len);
		src[i] = ' ';
		src[len - 1] = '\0';
		i++;
		while (i < len - 1)
		{
			src[i] = str[i - 1];
			i++;
		}
	}
	return (src);
}

char	*apply_options(char *str, char c, t_options *opt)
{
	if (opt->precision == 0 && opt->hashtag == 1 && c == 'o' && ft_atoi(str) == 0)
		return ("0");
	if (opt->precision != -1)
		str = apply_precision(str, opt);
	if (opt->hashtag != 0 && (c == 'x' || c == 'X'))
		str = apply_hashtag_x(str, opt);
	if (opt->largeur != -1)
		str = apply_largeur(str, opt);
	if (opt->zero != 0)
		str = apply_zero(str, opt);
	if (opt->space != 0)
		str = apply_space(str, opt);
	if (opt->plus != 0)
		str = apply_plus(str, opt);
	if (opt->hashtag != 0 && c != 'x' && c != 'X')
		str = apply_hashtag(str, opt);
	if (opt->moins != 0)
		str = apply_moins(str, opt);
	return (str);
}
