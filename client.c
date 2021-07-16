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

int main(int argc, char **argv)
{
	int		pid;
	char 	*msg;

	pid = ft_atoi(argv[1]);
	msg = argv[2];
	printf("pid %s\n", argv[1]);
	
	return(0);
}