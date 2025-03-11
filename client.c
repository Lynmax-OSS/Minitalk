#include "minitalk.h"

volatile sig_atomic_t g_server = BUSY;

void	end_handler(int signo)
{
	write(STDOUT_FILENO, "ok!\n", 4);
	exit(EXIT_SUCCESS);
}

void	ack_handler(int signo)
{
	g_server = READY;
}

void send_char(char c, pid_t server)
{
	int bit;

	bit = 0;
	while(bit < CHAR_BIT)
	{
		if(c & (0b10000000 >> bit))
			Kill(server, SIGUSR1);
		else
			Kill(server, SIGUSR2);
		++bit;
		while (BUSY == g_server) 
			usleep(42);
		g_server = BUSY;
	}
}

int main(int ac, char **av)
{
	pid_t	server_pid;
	char	*message;

	if (ac != 3)
	{
		ft_putstr_fd("Usage: ../client [PID] [message]\n", 2);
		return 1;
	}
	server_pid = (ft_atoi(av[1]));
	message = av[2];
	Signal(SIGUSR1, ack_handler, false);
	Signal(SIGUSR2, end_handler, false);
	while (*message) 
		send_char(*message++, server_pid);
	send_char('\0', server_pid);

	return 0;
}