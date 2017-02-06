/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:08:50 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/06 14:48:55 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft.h"
# include <wchar.h>

typedef struct	s_options
{
	int		moins;
	int		positiv;
	int		hashtag;
	int		zero;
	int		space;
	int		precision;
	int		largeur;
	int		lenstr;
	int		taille;
	int		count;
	int		i;
	char	type;
}				t_options;

typedef struct	s_flags
{
	char		*str;
	char		*(*f)(va_list ap, char c, t_options *options);
}				t_flags;

int				ft_printf(char *str, ...);
char			*parsing(va_list ap, char c, t_options *options);
int				option_detect(char *str, int i, t_options *options);
char			*s_arg(va_list ap, char c, t_options *options);
char			*int_arg(va_list ap, char c, t_options *opt);
int				ma_fct(char *str, int i);
void			option1(char c, t_options *opt);
int				option2(char *str, int i, t_options *opt);
int				option3(char *str, int i, t_options *opt);
int				option4(char *str, int i, t_options *opt);
int				option41(char *str, int i, t_options *opt);
int				option42(char *str, int i, t_options *opt);
void			init_flags(t_options *opt);
long long		signed_cast(va_list ap, t_options *opt);
uintmax_t		unsigned_cast(va_list ap, t_options *opt);
char			*ft_itoa_base(intmax_t value, int base);
char			dou_arg(va_list ap, char c, t_options *opt);
int				in_out(va_list ap, char c, t_options *opt);
char			*apply_options(char *str, char c, t_options *opt);
char			*apply_options_bis(char *str, t_options *opt);
char			*apply_space(char *str, t_options *opt);
char			*apply_zero(char *str, t_options *opt);
char			*apply_left(char *str, t_options *opt);
char			*plus(char *str, char *src, int j, t_options *opt);
char			*apply_hashtag(char *str, char c, t_options *opt);
char			*ws_arg(va_list ap, char c, t_options *opt);
char			*c_arg(va_list ap, char c, t_options *opt);
char			*p_arg(va_list ap, char c, t_options *opt);
char			*ft_wputchar(wchar_t w);
char			*ft_itoa_base_uint(uintmax_t value, int base);
char			*pct_arg(va_list ap, char c, t_options *opt);
char			*ft_maj(char *res);
unsigned int	ft_valeur_absolue(int nb);
i

#endif
