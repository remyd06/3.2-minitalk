/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:14:23 by rdedola           #+#    #+#             */
/*   Updated: 2024/07/21 16:11:57 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../ft_printf/ft_printf.h"

void    cat_msg(int msg, int j, int act)
{
    static char       *c = NULL;
    static int        i = 0;

    c = ft_realloc(c, i + 1, j + 2);
    if (c == NULL)
        exit(1);
    c[i] = (char)msg;
    i++;
    if (act == 1)
    {
        c[i] = '\0';
        ft_printf("Message from client: ");
        ft_putstring(c);
        free(c);
        c = NULL;
        i = 0;
    }
}

void    ft_handler(int signal, siginfo_t *info, void *context)
{
    static int    bit = 0;
    static int    i = 0;
    static int    j = 0;

    (void)context;
    if (signal == SIGUSR1)
        i |= (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        if (i == '\0')
        {
            cat_msg(i, j, 1);
            ft_printf("\n");
            kill(info->si_pid, SIGUSR1);
        }
        else
        {
            j++;
            cat_msg(i, j, 0);    
        }
        bit = 0;
        i = 0;
    }
}

int main()
{
    pid_t   pid;
    struct sigaction sa;

    pid = getpid();
    ft_printf("\033[1;33m");
    ft_printf("███████╗███████╗██████╗ ██╗   ██╗███████╗██████╗ \n");
	ft_printf("██╔════╝██╔════╝██╔══██╗██║   ██║██╔════╝██╔══██╗\n");
	ft_printf("███████╗█████╗  ██████╔╝██║   ██║█████╗  ██████╔╝\n");
	ft_printf("╚════██║██╔══╝  ██╔══██╗╚██╗ ██╔╝██╔══╝  ██╔══██╗\n");
	ft_printf("███████║███████╗██║  ██║ ╚████╔╝ ███████╗██║  ██║\n");
	ft_printf("╚══════╝╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝\n");
    ft_printf("\033[0m");
    ft_printf("\033[1m\033[3mProcess ID = %d\033[0m\n", pid);
    sa.sa_sigaction = ft_handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
    {
        pause();
    }
    return (0);
}
