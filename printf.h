/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:08:50 by sait-ben          #+#    #+#             */
/*   Updated: 2017/01/04 15:03:53 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include "./Libft/libft.h"

# define BUFF_SIZE2 100

typedef struct	s_options
{	
	int			left_align;
	int 		positiv;
	int 		hashtag;
	int 		zero;
	int 		space;
	int 		precision;
	int 		taille;
	int			j;
	char 		buff[BUFF_SIZE2];
}				t_options;

typedef struct	s_flags
{
	char		*str;
	int			(*f)(va_list ap, char c, t_options *options);
}				t_flags;

void	myprintf(char *str, ...);
int		parsing(va_list ap, char c, t_options *options);
void	option_detect(char c, t_options *options);
int		s_arg(va_list ap, char c, t_options *options);

# endif
