/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:46:01 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/19 11:46:17 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	ft_list_new(void (*free_item)(void *))
{
	t_list	new_list;

	new_list.len = 0;
	new_list.free_item = free_item;
	return (new_list);
}

void	ft_list_clear(t_list *list)
{
	size_t	i;
	t_lnode	*temp;

	i = 0;
	while (i < list->len)
	{
		list->free_item(list->first->item);
		temp = list->first;
		list->first = temp->after;
		free(temp);
		i++;
	}
	list->len = 0;
}
