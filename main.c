/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:34:52 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/17 14:40:11 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "./sources/printf.h"
#include <limits.h>

int		main()
{
	int	len;
	int	len2;
		
	len = ft_printf("%0+5d", 42);
//	printf("len = %d\n", len);
	setlocale(LC_ALL, "");
	len2 = printf("%0+5d", 42);
//	printf("len2 = %d\n", len2);
	ft_putchar('\n');
	return (0);
}
