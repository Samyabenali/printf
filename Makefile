# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sait-ben <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 15:12:18 by sait-ben          #+#    #+#              #
#    Updated: 2017/02/03 17:10:38 by sait-ben         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CFLAGS	= -Wall -Wextra -Werror

OPTION	= -c

INCLUDE	= libft.h \
		  printf.h \
		  get_next_line.h

SRCS 	= ft_atoi.c \
		  ft_bzero.c \
		  ft_isalpha.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_itoa_base.c \
		  ft_lstadd.c \
		  ft_lstdel.c \
		  ft_lstdelone.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_lstnew.c \
		  ft_memalloc.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memdel.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_sort_params.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_strclr.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strdel.c \
		  ft_strdup.c \
		  ft_strequ.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlen.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strnequ.c \
		  ft_strnew.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strsplit.c \
		  ft_strstr.c \
		  ft_strsub.c \
		  ft_strtrim.c \
		  ft_sqrt.c \
		  ft_swap.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  get_next_line.c \
		  ft_printf.c \
		  convert.c \
		  options.c \
		  options2.c \
		  int_arg.c \
		  s_arg.c \
		  cast.c \
		  dou_arg.c \
		  apply_options.c \
		  in_out.c \
		  apply_options2.c \
		  apply_options3.c \
		  w_putchar.c \
		  c_arg.c \
		  p_arg.c \
		  ft_itoa_base_uint.c \
		  pct_arg.c

OBJS	= $(SRCS:%.c=%.o)

all :	$(NAME)

$(NAME)	:
	gcc $(OPTION) $(SRCS) -I $(HEADER)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -f $(OBJS)

fclean :	clean
	rm -rf $(NAME)

re :	fclean all