/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:57:11 by keteo             #+#    #+#             */
/*   Updated: 2025/03/20 18:57:11 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int signo, siginfo_t *info, void *more_info)
{
	(void)more_info;
	static char		c;
	static int		bit;
	static pid_t	client;

	client = info->si_pid;
	if (SIGUSR1 == signo)
		c |= (0b10000000 >> bit);
	else if (SIGUSR2 == signo)
		c &= ~(0b10000000 >> bit);
	++bit;
	if (CHAR_BIT == bit)
	{
		bit = 0;
		if ('\0' == c)
		{
			write(STDOUT_FILENO, "\n", 1);
			Kill(client, SIGUSR2);
			return ;
		}
		write(STDOUT_FILENO, &c, 1);
	}
	kill(client, SIGUSR1);
}

int main(void)
{
	ft_printf("This is the getpid:%d\n", getpid());
	Signal(SIGUSR1, handler, true);
	Signal(SIGUSR2, handler, true);

	while (1)
	{
		pause();
	}
	return EXIT_SUCCESS;
}