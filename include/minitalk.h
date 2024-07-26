/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:09:18 by rdedola           #+#    #+#             */
/*   Updated: 2024/07/18 19:12:49 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 600
# define _POSIX_C_SOURCE 200112L


#include "../ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <stddef.h>


int		ft_atoi(char *str);
void	ft_putstring(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char    *ft_realloc(char *ptr, size_t old_size, size_t new_size);


#endif