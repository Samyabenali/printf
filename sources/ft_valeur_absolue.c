/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valeur_absolue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:29:16 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/06 14:30:40 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned int	ft_valeurabsolue(int nb)
{
	if (nb >= 0)
		return ((unsigned int)nb);
	nb = -nb;
	return ((unsigned int)nb);
}
