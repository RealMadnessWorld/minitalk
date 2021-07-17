#include "minitalk.h"

void	bin_conv(unsigned char x, int pid)
{
	unsigned char bit;

	bit = 0b10000000;
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

int main(int argc, char **argv)
{
	int		pid;
	char 	*msg;

	if (argc != 3)
		exit(0);
	pid = 0;
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (*msg)
	{
		bin_conv(*msg, pid);
		msg++;
	}
	bin_conv(0, pid);
	return(0);
}