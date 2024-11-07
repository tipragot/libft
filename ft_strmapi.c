/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:41:54 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/07 00:42:12 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	char	*result;

	size = ft_strlen(s);
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	result[size] = '\0';
	while (size-- != 0)
		result[size] = f(size, s[size]);
	return (result);
}
