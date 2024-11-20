/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:40:35 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/20 17:58:38 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_handle(int fd, char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(fd, va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(fd, va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(fd, va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(fd, va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr(fd, va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthex(fd, va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (ft_puthex(fd, va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar(fd, '%'));
	return (0);
}

int	ft_printf_fd(const int fd, const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_handle(fd, format[++i], args);
		else
			count += ft_putchar(fd, format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_handle(1, format[++i], args);
		else
			count += ft_putchar(1, format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
