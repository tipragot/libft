/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:02:30 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/19 11:30:58 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_list_push_first(t_list *list, void *item)
{
	t_lnode	*new_node;

	new_node = malloc(sizeof(t_lnode));
	if (!new_node)
	{
		list->free_item(item);
		return (0);
	}
	new_node->item = item;
	if (list->len == 0)
		list->last = new_node;
	else
	{
		list->first->before = new_node;
		new_node->after = list->first;
	}
	list->first = new_node;
	list->len++;
	return (1);
}

int	ft_list_push_last(t_list *list, void *item)
{
	t_lnode	*new_node;

	new_node = malloc(sizeof(t_lnode));
	if (!new_node)
	{
		list->free_item(item);
		return (0);
	}
	new_node->item = item;
	if (list->len == 0)
		list->first = new_node;
	else
	{
		list->last->after = new_node;
		new_node->before = list->last;
	}
	list->last = new_node;
	list->len++;
	return (1);
}

int	ft_list_push_at(t_list *list, size_t index, void *item)
{
	t_lnode	*new_node;
	t_lnode	*next_node;

	if (index > list->len)
		return (0);
	else if (index == 0)
		return (ft_list_push_first(list, item));
	else if (index == list->len)
		return (ft_list_push_last(list, item));
	new_node = malloc(sizeof(t_lnode));
	if (!new_node)
	{
		list->free_item(item);
		return (0);
	}
	new_node->item = item;
	next_node = ft_list_get_node(list, index);
	new_node->before = next_node->before;
	new_node->after = next_node;
	next_node->before = new_node;
	list->len++;
	return (1);
}
