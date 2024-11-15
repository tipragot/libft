/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:46:01 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/15 12:27:49 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <strings.h>

t_list	*ft_list_new(void)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->len = 0;
	return (new_list);
}

void	ft_list_free(t_list *list, void (*free_content)(void *))
{
	if (!list)
		return ;
	ft_list_clear(list, free_content);
	free(list);
}
