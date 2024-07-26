# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 10:24:39 by rdedola           #+#    #+#              #
#    Updated: 2024/07/10 05:42:07 by rdedola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF = libftprintf.a

SRCS =	ft_putchar.c \
		ft_putnbr_hex_low.c \
		ft_putnbr_hex_upp.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putnbr_uns.c \
		ft_print_adress.c \
		ft_printf.c \

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

DEF_COLOR = \033[0;39m
COLOR = \033[1;32m

all:		${PRINTF}

%.o:		%.c
		@${CC} ${CFLAGS} -c $? -o $@

${PRINTF}:	${OBJS}
		@ar rcs $@ $?

clean:
		@${RM} ${OBJS}

fclean:		clean
		@${RM} ${PRINTF}

re:			fclean all

.PHONY: all clean fclean re