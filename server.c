#include "minitalk.h"

void handler(int signo, siginfo_t *info, void *more_info)
{
	()more_info;
}

int main(void)
{
	ft_printf("This is the getpid:%d\n", getpid());
	Signal(Sigusr1, handler, true);
	Signal(Sigusr2, handler, true);

	while (1)
	{
		pause();
	}
	return EXIT_SUCCESS;
}