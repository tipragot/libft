/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:51:40 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/15 11:59:55 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(int fd, char c)
{
	return (write(fd, &c, 1));
}

int	ft_putstr(int fd, char *str)
{
	int	len;

	if (str == NULL)
		return (ft_putstr(fd, "(null)"));
	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
	return (len);
}
