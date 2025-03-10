#include "minitalk.h"

void handler(int signo, siginfo_t *info, void *more_info)
{
	(void)more_info;
	write(STDOUT_FILENO, "Signal received\n", 16);
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