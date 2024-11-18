/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:46:01 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/18 20:25:55 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_list_new(void (*free_item)(void *))
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->len = 0;
	new_list->free_item = free_item;
	return (new_list);
}

void	ft_list_free(t_list *list)
{
	if (!list)
		return ;
	ft_list_clear(list);
	free(list);
}
