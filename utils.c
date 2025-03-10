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