/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_opt->c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:24:27 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/17 15:05:54 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*apply_largeur(char *str, t_options *opt)
{
	char	*src;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((int)ft_strlen(str) >= opt->largeur)
		return (str);
	if (opt->largeur != 0 && opt->type == 'c' && *str == 0)
		opt->slen = 1;
	src = (char*)malloc(sizeof(char) * (opt->largeur + 1));
	while (i < (opt->largeur - (int)ft_strlen(str) - opt->slen))
	{
		src[i] = ' ';
		i++;
	}
	while (j < (int)ft_strlen(str))
		src[i++] = str[j++];
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

char	*apply_precision(char *str, char c,  t_options *opt)
{
	int		i;
	int		j;
	char	*src;
	int		len;

	i = 0;
	j = 0;	
	len = (int)ft_strlen(str);
	if (opt->precision == 0 && ft_atoi(str) == 0 && opt->type != '%' && c != 'p')
	{
		str = (char*)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	if (len >= opt->precision && c == 's')
		return (ft_strsub(str, 0, opt->precision));
	if (len >= opt->precision && c == 'S')
		return (ft_strsubwchar(str, 0, opt));
	if ((int)ft_strlen(str) >= opt->precision)
		return (str);
	if (len < opt->precision && (opt->type == 'c' || opt->type == 'C'))
		return (str);
	if (opt->precision != -1 && opt->type == '%')
		return (str);
	else
	{
		len = 0;
		if (ft_atoi(str) < 0)
			return (apply_precision_neg(str, opt));
		src = (char*)malloc(sizeof(char) * opt->precision + 1);
		while ((i < (opt->precision - (int)ft_strlen(str))) && c != 's')
		{
			src[i] = '0';
			i++;
		}
		src[opt->precision] = '\0';
		while ((i < (opt->precision - (int)ft_strlen(str))) && c != 's')
		{
			src[i] = ' ';
			i++;
		}
		src[opt->precision] = '\0';
		while (str[j])
		{
			src[i] = str[j];
			i++;
			j++;
		}
		src[i] = '\0';
		opt->zero = 0;
	}
	return (src);
}

char	*apply_plus(char *str, char c, t_options *opt)
{
	int		i;
	char	*src;

	(void)opt;
	i = 0;
	if (ft_atoi(str) < 0 || ft_strchr("di", c) == NULL)
		return (str);
	if (opt->zero != 0 && str[0] == '0')
	{	
		str[0] = '+';
		return (str);
	}	
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
		i--;
		str[i] = '+';
		return (str);
	}
	else
	{	
		src = (char*)malloc(sizeof(char) * ft_strlen(str) + 2);
		src[i] = '+';
		i++;
		src[ft_strlen(str) + 1] = '\0';
		while (i <= (int)ft_strlen(str))
		{
			src[i] = str[i - 1];
			i++;
		}
	}
	return (src);
}

char	*apply_space(char *str, char c, t_options *opt)
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
		if (opt->space == 1 && opt->zero == 1 && ft_atoi(str) == 0)
			len--;
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
	char	*src;

	src = str;
	if (opt->precision == 0 && opt->hashtag == 1 && (c == 'o' || c == 'O') && ft_atoi(str) == 0)
		return ("0");
	if (opt->precision != -1)
		src = apply_precision(src, c, opt);
	if (opt->hashtag != 0 && (c == 'x' || c == 'X'))
		src = apply_hashtag_x(src, opt);
	if (opt->largeur != -1)
		src = apply_largeur(src, opt);
	if (opt->zero != 0)
		src = apply_zero(src, opt);
	if (opt->space != 0)
		src = apply_space(src, c, opt);
	if (opt->plus != 0)
		src = apply_plus(src, c, opt);
	if (opt->hashtag != 0 && c != 'x' && c != 'X')
		src = apply_hashtag(src, opt);
	if (opt->moins != 0)
		src = apply_moins(src, opt);
	return (src);
}
