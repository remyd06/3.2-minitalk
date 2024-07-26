/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdedola <rdedola@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:14:14 by rdedola           #+#    #+#             */
/*   Updated: 2024/07/21 15:50:45 by rdedola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../ft_printf/ft_printf.h"

void check_message(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("Server succesfully received your message.\n");
        exit (0);
    }
}

void    send_msg(int pid, char i)
{
    int    bit;

    bit = 0;
    while (bit < 8)
    {
        if ((i & (0x01 << bit)) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(1000);
        bit++;
    }
}

int main(int argc, char **argv)
{
    pid_t server_pid;
    int i;

    server_pid = ft_atoi(argv[1]);
    if (argc != 3)
    {
        printf("Wrong arguments, only PID and your text to send.\n");
        return (0);
    }
    ft_printf("\033[1;33m");
    ft_printf(" ██████╗██╗     ██╗███████╗███╗   ██╗████████╗\n");
    ft_printf("██╔════╝██║     ██║██╔════╝████╗  ██║╚══██╔══╝\n");
    ft_printf("██║     ██║     ██║█████╗  ██╔██╗ ██║   ██║   \n");
    ft_printf("██║     ██║     ██║██╔══╝  ██║╚██╗██║   ██║   \n");
    ft_printf("╚██████╗███████╗██║███████╗██║ ╚████║   ██║   \n");
    ft_printf(" ╚═════╝╚══════╝╚═╝╚══════╝╚═╝  ╚═══╝   ╚═╝   \n");
    ft_printf("\033[0m");
    i = 0;
    while (argv[2][i])
    {
        send_msg(server_pid, argv[2][i]);
        i++;
    }
    signal(SIGUSR1, check_message);
    send_msg(server_pid, '\0');
    while (1)
    {
        pause();
    }
}