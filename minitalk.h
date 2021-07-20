#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

typedef struct s_info
{
	int				index;
	unsigned char	cha;
	char			str[4096];
	int				flag;
	int				c_pide;
}				t_info;

int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	tr_msg(t_info *info);
void	inv_bin_conv(int x);
void	bin_conv(unsigned char x, int pid);
void	inv_bin_conv_b(int x);
void	send_conf(t_info *info);
void	guess_who(t_info *info);
void	start_that_stuff(t_info *info);
char	*ft_itoa(int n);
void	bin_conv_b(unsigned char x, int pid);
void	confirmation();
void	send_text(int pid, char *pid_str, char *msg);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *str);

#endif