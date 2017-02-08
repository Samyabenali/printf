/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:08:50 by sait-ben          #+#    #+#             */
/*   Updated: 2017/02/08 13:17:19 by sait-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft.h"
# include <wchar.h>

# define BUFF_SIZE2 200

typedef struct	s_options
{
	int		moins;
	int		plus;
	int		hashtag;
	int		zero;
	int		space;
	int		precision;
	int		largeur;
	int		lenstr;
	int		taille;
	int		count;
	int		j;
	char	type;
	char	buff[BUFF_SIZE2];
}				t_options;

typedef struct	s_flags
{
	char		*str;
	char		*(*f)(va_list ap, char c, t_options *options);
}				t_flags;

int				ft_printf(char *str, ...);
char			*parsing(va_list ap, char c, t_options *opt);
int				option_detect(char *str, int i, t_options *opt);
int				def_opt(char *str, int i,t_options *opt);
int				def_opt_bis(char *str, int i,t_options *opt);
int				largeur(char *str, int i,t_options *opt);
int				precision(char *str, int i,t_options *opt);
int				def_opt4(char *str, int i,t_options *opt);
char			*s_arg(va_list ap, char c, t_options *opt);
char			*int_arg(va_list ap, char c, t_options *opt);
int				ma_fct(char *str, int i);
int				def_opt_bis(char *str, int i, t_options *opt);
void			init_flags(t_options *opt);
long long		signed_cast(va_list ap, t_options *opt);
uintmax_t		unsigned_cast(va_list ap, t_options *opt);
char			*ft_itoa_base(intmax_t value, int base);
char			*dou_arg(va_list ap, char c, t_options *opt);
int				in_out(va_list ap, char c, t_options *opt);
char			*apply_options(char *str, char c, t_options *opt);
char			*apply_moins(char *res, t_options *opt);
char			*apply_hashtag(char *res, t_options *opt);
char			*apply_zero(char *res, t_options *opt);
char			*apply_hashtag_x(char *res, t_options *opt);
char			*ws_arg(va_list ap, char c, t_options *opt);
char			*c_arg(va_list ap, char c, t_options *opt);
char			*p_arg(va_list ap, char c, t_options *opt);
char			*ft_wputchar(wchar_t w);
char			*ft_itoa_base(intmax_t value, int base);
char			*ft_itoa_base_uint(uintmax_t value, int base);
char			*pct_arg(va_list ap, char c, t_options *opt);
char			*ft_maj(char *res);
unsigned int	ft_valeurabsolue(int nb);

#endif
