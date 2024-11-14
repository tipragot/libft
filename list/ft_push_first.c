/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:02:30 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/14 15:52:41 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

int	ft_push_first(t_list *list, void *content)
{
	t_lnode	*new_node;

	new_node = malloc(sizeof(t_lnode));
	if (!new_node)
		return (1);
	new_node->content = content;
	if (list->len == 0)
		list->last = new_node;
	else
	{
		list->first->before = new_node;
		new_node->next = list->first;
	}
	list->first = new_node;
	list->len++;
	return (0);
}
