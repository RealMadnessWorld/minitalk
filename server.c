#include "minitalk.h"

t_info info;

void	inv_bin_conv(int x)
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

void	tr_msg(t_info *info)
{
	int i;

	pause();
	if (info->index == 8)
	{
		i = 0;
		while (info->str[i] != 0)
			i++;
		info->str[i] = info->cha;
		if (info->cha == '\0')
		{
			ft_putstr_fd(info->str, 1);
			ft_putchar_fd('\n', 1);
			i = 0;
			while (i < 4096)
			{
				info->str[i] = 0;
				i++;
			}
		}
		info->index = 0;
		info->cha = 0;
	}
}

int main(void)
{
	pid_t	pid;
	int		i;

	info.index = 0;
	info.cha = 0;
	i = 0;
	while (i < 4096)
	{
		info.str[i] = 0;
		i++;
	}
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, inv_bin_conv);
	signal(SIGUSR2, inv_bin_conv);
	while (1)
		tr_msg(&info);
	return (0);
}