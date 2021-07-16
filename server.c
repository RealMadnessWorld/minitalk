#include "minitalk.h"

void	bin_conv(const char x, int pid)
{
	int bit;

	bit = 0b100000000;
	while (bit != 0)
	{
		if ((bit & x))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit = bit >> 1;
		usleep(100);
	}
}

int main(void)
{
	pid_t pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	while ()
	return (0);
}