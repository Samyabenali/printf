/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:21:03 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/03 17:38:24 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_flags(t_options *opt)
{
	opt->left_align = 0;
	opt->positiv = 0;
	opt->hashtag = 0;
	opt->zero = 0;
	opt->space = 0;
	opt->precision = 0;
	opt->largeur = 0;
	opt->taille = 0;
}
