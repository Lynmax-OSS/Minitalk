#include "minitalk.h"

int main(void)
{
	ft_printf("This is the getpid:%d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);

	while (1)
	{
		pause();
	}
	return EXIT_SUCCESS;
}