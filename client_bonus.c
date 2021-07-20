#include "minitalk.h"

void	bin_conv_b(unsigned char x, int pid)
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

void	confirmation()
{
	write(1, "Aknowledged\n", 12);
	exit (0);
}

void	send_text(int pid, char *pid_str, char *msg)
{
	while (*pid_str)
	{
		bin_conv_b(*pid_str, pid);
		pid_str++;
	}
	bin_conv_b('\0', pid);
	while (*msg)
	{
		bin_conv_b(*msg, pid);
		msg++;
	}
	bin_conv_b('\0', pid);
}

int	main(int argc, char **argv)
{
	int pide_serv;
	pid_t pid_c;
	char *pid_str;
	char *msg;

	if (argc != 3)
		exit (0);
	printf("oi\n");
	signal(SIGUSR1, confirmation);
	msg = argv[2];
	pid_c = getpid();
	pide_serv = ft_atoi(argv[1]);
	pid_str = ft_itoa(pid_c);
	send_text(pide_serv, pid_str, msg);
	pause();
	free(pid_str);
	return(0);
}