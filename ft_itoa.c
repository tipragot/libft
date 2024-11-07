/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:32:09 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/07 00:32:45 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	chars[11];
	int		i;
	int		f;
	char	*result;

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
	result = malloc(10 - i + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, &chars[i + 1], 10 - i);
	result[10 - i] = '\0';
	return (result);
}
