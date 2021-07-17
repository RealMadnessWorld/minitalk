#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

typedef struct s_info
{
	int index;
	unsigned char cha;
	char str[4096];
}				t_info;

int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	tr_msg(t_info *info);
void	inv_bin_conv(int x);
void	bin_conv(unsigned char x, int pid);

#endif