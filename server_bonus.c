#include "minitalk.h"

t_info info;

void	inv_bin_conv_b(int x)
{
	unsigned char	bit;

	bit = 0b10000000;
	if (x == SIGUSR2)
		info.index++;
	if (x == SIGUSR1)
	{
		bit = bit >> info.index;
		info.cha = info.cha | bit;
		info.index++;
	}
}

void	start_that_stuff(t_info *info)
{
	pid_t pide;
	int i;

	i = 0;
	info->cha = 0;
	info->index = 0;
	info->flag = 0;
	while (i < 4096)
	{
		info->str[i] = 0;
		i++;
	}
	pide = getpid();
	ft_putnbr_fd(pide, 1);
	ft_putchar_fd('\n', 1);

}

void	send_conf(t_info *info)
{
	ft_putstr_fd(info->str, 1);
	ft_putchar_fd('\n', 1);
	kill(info->c_pide, SIGUSR1);
	info->flag = 0;
}

void	guess_who(t_info *info)
{
	int i;

	printf("%i\n", info->flag);
	i = 0;
	if (info->flag == 0)
	{
		info->c_pide = ft_atoi(info->str);
		info->flag = 1;
	}
	else
		send_conf(info);
	while (i < 4096)
	{
		info->str[i] = 0;
		i++;
	}
}

int	main(void)
{
	int i;

	start_that_stuff(&info);
	signal(SIGUSR1, inv_bin_conv_b);
	signal(SIGUSR2, inv_bin_conv_b);
	while (1)
	{
		pause();
		if (info.index == 8)
		{
			printf("str: %s\n", info.str);
			i = 0;
			while (info.str[i] != 0)
				i++;
			info.str[i] = info.cha;
			if (info.cha == '\0')
			{
				printf("hi\n");
				guess_who(&info);
			}
			info.index = 0;
			info.cha = 0;
		}
	}
	return (0);
}