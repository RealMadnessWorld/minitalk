#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

int		ft_atoi(const char *str)
{
	int neg;
	int n;

	n = 0;
	neg = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = 1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
		n = n * 10 + (*str++ - '0');
	if (neg == 1)
		return (-n);
	else
		return (n);
}

static void		printnbr(int n, int fd)
{
	if (n >= 10)
		printnbr(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	int		x;

	x = n;
	if (x < 0)
	{
		if (x == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		ft_putchar_fd('-', fd);
		x = -x;
	}
	printnbr(x, fd);
}