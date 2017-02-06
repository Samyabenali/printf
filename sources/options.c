/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:00:23 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/06 15:53:08 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		def_opt(char *str, int i, t_options *opt)
{
	int i_init;

	i_init = i;
	while (str[i] == '-')
	{
		opt->moins = 1;
		i++;
	}
	while (str[i] == '+')
	{
		opt->plus = 1;
		i++;
	}
	while (str[i] == '0')
	{
		opt->zero = 1;
		i++;
	}
	if (i_init != i)
		i = def_opt(str, i, opt);
	i = def_opt_bis(str, i, opt);
	return (i);
}

int		def_opt_bis(char *str, int i, t_options *opt)
{
	int i_init;

	i_init = i;
	while (str[i] == ' ')
	{
		opt->space = 1;
		i++;
	}
	while (str[i] == '#')
	{
		opt->hashtag = 1;
		i++;
	}
	if (i != i_init)
		i = def_opt(str, i, opt);
	return (i);
}

int		def_opt2(char *str, int i, t_options *opt)
{
	if (str[i] >= 48 && str[i] <= 57)
		opt->largeur = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		opt->largeur = (opt->largeur) * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}

int		def_opt3(char *str, int i, t_options *opt)
{
	if (str[i] == '.')
	{
		i++;
		opt->precision = 0;
		while (str[i] <= 57 && str[i] >= 48)
		{
			opt->precision = opt->precision * 10 + (str[i] - '0');
			i++;
		}
	}
	return (i);
}

int		option_detect(char *str, int i, t_options *opt)
{
	if (str[i] == 'h')
	{
		i++;
		if (str[i] == 'h')
		{
			opt->taille = 1;
			i++;
			i = option_detect(str, i, opt);
		}
		else
			opt->taille = 2;
	}
	if (str[i] == 'l')
	{
		i++;
		if (str[i] == 'l')
		{
			opt->taille = 4;
			i++;
			i = option_detect(str, i, opt);
		}
		else
			opt->taille = 3;
	}
	return (i);
}
