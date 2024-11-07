/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:38:04 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/07 00:45:44 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
}
