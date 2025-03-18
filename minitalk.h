#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

enum
{
	READY,
	BUSY,
};

void	Signal(int , void *, bool);
void	Kill(pid_t pid, int signo);
int		ft_printf(const char *format, ...);
void	ft_putstr_fd(char *c, int fd);
int		ft_atoi(const char *str);

#endif