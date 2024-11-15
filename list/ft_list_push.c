/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:02:30 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/15 11:31:06 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

int	ft_push_last(t_list *list, void *content)
{
	t_lnode	*new_node;

	new_node = malloc(sizeof(t_lnode));
	if (!new_node)
		return (1);
	new_node->content = content;
	if (list->len == 0)
		list->first = new_node;
	else
	{
		list->last->next = new_node;
		new_node->before = list->last;
	}
	list->last = new_node;
	list->len++;
	return (0);
}

int	ft_push_at(t_list *list, size_t index, void *content)
{
	t_lnode	*new_node;
	t_lnode	*next_node;

	if (index > list->len)
		return (1);
	else if (index == 0)
		return (ft_push_first(list, content));
	else if (index == list->len)
		return (ft_push_last(list, content));
	new_node = malloc(sizeof(t_lnode));
	if (!new_node)
		return (1);
	new_node->content = content;
	next_node = ft_list_get_node(list, index);
	new_node->before = next_node->before;
	new_node->next = next_node;
	next_node->before = new_node;
	list->len++;
	return (0);
}
