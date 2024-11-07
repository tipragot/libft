/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:39:27 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/07 00:39:38 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*n;

	size = 0;
	while (s[size])
		size++;
	n = malloc(size + 1);
	if (n == NULL)
		return (n);
	i = 0;
	while (i < size)
	{
		n[i] = s[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}
