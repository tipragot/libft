/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:54:57 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/15 11:59:49 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr(int fd, int n)
{
	char	chars[11];
	int		i;
	int		f;

	i = 10;
	f = 1;
	if (n < 0)
		f = -1;
	while (n != 0)
	{
		chars[i--] = (n % 10) * f + '0';
		n /= 10;
	}
	if (i == 10)
		chars[i--] = '0';
	if (f == -1)
		chars[i--] = '-';
	write(fd, &chars[i + 1], 10 - i);
	return (10 - i);
}

int	ft_putunbr(int fd, unsigned int n)
{
	char	chars[10];
	int		i;

	i = 9;
	while (n != 0)
	{
		chars[i--] = (n % 10) + '0';
		n /= 10;
	}
	if (i == 9)
		chars[i--] = '0';
	write(fd, &chars[i + 1], 9 - i);
	return (9 - i);
}

int	ft_puthex(int fd, unsigned long long n, int uppercase)
{
	char	chars[16];
	int		i;

	i = 15;
	while (n != 0)
	{
		if (uppercase)
			chars[i--] = "0123456789ABCDEF"[n % 16];
		else
			chars[i--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	if (i == 15)
		chars[i--] = '0';
	write(fd, &chars[i + 1], 15 - i);
	return (15 - i);
}

int	ft_putptr(int fd, void *ptr)
{
	if (ptr == NULL)
		return (ft_putstr(fd, "(nil)"));
	return (ft_putstr(fd, "0x") + ft_puthex(fd, (unsigned long long)ptr, 0));
}
