# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 08:09:22 by rdedola           #+#    #+#              #
#    Updated: 2024/07/09 15:29:54 by rdedola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRCDIR = src
INCDIR = include
LIBFTPRINTFDIR = ft_printf

SRCS_SERVER = $(SRCDIR)/server.c $(SRCDIR)/utils.c
SRCS_CLIENT = $(SRCDIR)/client.c $(SRCDIR)/utils.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -I$(INCDIR) -I$(LIBFTPRINTFDIR)
LDFLAGS = -L$(LIBFTPRINTFDIR) -lftprintf

RM = rm -f

DEF_COLOR = \033[0;39m
COLOR = \033[1;32m

all: $(SERVER) $(CLIENT)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR)$<      ✓$(DEF_COLOR)"

$(SERVER): $(OBJS_SERVER)
	@$(MAKE) -C $(LIBFTPRINTFDIR)
	@$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) $(LDFLAGS)
	@echo "$(COLOR)╔═══════════════════════╗$(DEF_COLOR)"
	@echo "$(COLOR)║   Server compiled!    ║$(DEF_COLOR)"
	@echo "$(COLOR)╚═══════════════════════╝$(DEF_COLOR)"

$(CLIENT): $(OBJS_CLIENT)
	@$(MAKE) -C $(LIBFTPRINTFDIR)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) $(LDFLAGS)
	@echo "$(COLOR)╔═══════════════════════╗$(DEF_COLOR)"
	@echo "$(COLOR)║   Client compiled!    ║$(DEF_COLOR)"
	@echo "$(COLOR)╚═══════════════════════╝$(DEF_COLOR)"

clean:
	@$(MAKE) -C $(LIBFTPRINTFDIR) clean
	@$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	@echo "$(COLOR)╔═══════════════════════╗$(DEF_COLOR)"
	@echo "$(COLOR)║   Minitalk cleaned!   ║$(DEF_COLOR)"
	@echo "$(COLOR)╚═══════════════════════╝$(DEF_COLOR)"

fclean: clean
	@$(MAKE) -C $(LIBFTPRINTFDIR) fclean
	@$(RM) $(SERVER) $(CLIENT)
	@echo "$(COLOR)╔═══════════════════════╗$(DEF_COLOR)"
	@echo "$(COLOR)║  Executables removed! ║$(DEF_COLOR)"
	@echo "$(COLOR)╚═══════════════════════╝$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
