#include "minitalk.h"

int main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr_fd("Usage: ./client [PID] [message]\n", 2);
		return 1;
	}
	kill(ft_atoi(av[1]), SIGUSR1);
	return 0;
}