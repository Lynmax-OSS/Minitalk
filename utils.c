/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:57:19 by keteo             #+#    #+#             */
/*   Updated: 2025/03/20 18:57:19 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	Signal(int signo, void *handler, bool use_siginfo)
{
	struct sigaction	sa = {0};

	if (use_siginfo) 
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);

	if (sigaction(signo, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error: sigaction\n", 2);
		exit(EXIT_FAILURE);
	}
}

void Kill(pid_t pid, int signo)
{
	if (kill(pid, signo) < 0)
	{
		ft_putstr_fd("Kill failed", 2);
		exit(EXIT_FAILURE);
	}
}