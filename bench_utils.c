/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 11:35:47 by nde-mace          #+#    #+#             */
/*   Updated: 2026/07/16 22:44:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	c = (num % 10) + '0';
	write(fd, &c, 1);
}

static void	ft_putfloat_fd(double num, int fd)
{
	int	integer_part;
	int	fractional_part;

	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	integer_part = (int)num;
	fractional_part = (int)((num - integer_part) * 100 + 0.5);
	if (fractional_part >= 100)
	{
		integer_part += 1;
		fractional_part -= 100;
	}
	ft_putnbr_fd(integer_part, fd);
	write(fd, ".", 1);
	if (fractional_part < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(fractional_part, fd);
}

static void	print_format(int fd, const char *fmt, int *i, va_list args)
{
	char	*str;

	if (fmt[*i] == 'd')
		ft_putnbr_fd(va_arg(args, int), fd);
	else if (fmt[*i] == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		while (*str)
			write(fd, str++, 1);
	}
	else if (fmt[*i] == '.' && fmt[*i + 1] == '2' && fmt[*i + 2] == 'f')
	{
		ft_putfloat_fd(va_arg(args, double), fd);
		*i += 2;
	}
	else if (fmt[*i] == '%')
		write(fd, "%", 1);
}

void	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			print_format(fd, format, &i, args);
		}
		else
			write(fd, &format[i], 1);
		i++;
	}
	va_end(args);
}
