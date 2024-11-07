/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:43:25 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/07 00:43:44 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contains(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;
	char	*result;

	i = 0;
	while (ft_contains(set, s1[i]))
		i++;
	size = ft_strlen(s1 + i);
	while (size != 0 && ft_contains(set, s1[i + size - 1]))
		size--;
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	result[size] = '\0';
	while (size-- != 0)
		result[size] = s1[i + size];
	return (result);
}
