#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
#include <stdbool.h>
# include "ft_printf.h"

void	Signal(int , void *, bool);
int	ft_printf(const char *format, ...);
void	ft_putstr_fd(char *s, int fd);
int	ft_atoi(const char *str);

#endif