/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:47:55 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/19 14:31:13 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_lnode	*ft_list_move_remove_from(t_list *from, size_t index)
{
	t_lnode	*from_node;

	if (index >= from->len)
		return (NULL);
	from_node = ft_list_get_node(from, index);
	if (index == 0)
		from->first = from_node->after;
	else if (index == from->len - 1)
		from->last = from_node->before;
	else
	{
		from_node->before->after = from_node->after;
		from_node->after->before = from_node->before;
	}
	from->len--;
	return (from_node);
}

static void	ft_list_move_insert(t_lnode *from_node, t_list *to, size_t to_index,
		t_lnode *to_node)
{
	if (to->len == 0)
	{
		to->first = from_node;
		to->last = from_node;
	}
	else if (to_index == 0)
	{
		from_node->after = to->first;
		to->first->before = from_node;
		to->first = from_node;
	}
	else if (to_index == to->len)
	{
		from_node->before = to->last;
		to->last->after = from_node;
		to->last = from_node;
	}
	else
	{
		to_node = ft_list_get_node(to, to_index);
		from_node->before = to_node->before;
		from_node->after = to_node;
		to_node->before = from_node;
	}
}

void	ft_list_move(t_list *from, size_t from_index, t_list *to,
		size_t to_index)
{
	t_lnode	*from_node;

	from_node = ft_list_move_remove_from(from, from_index);
	if (!from_node)
		return ;
	if (to_index > to->len)
	{
		from->free_item(from_node->item);
		free(from_node);
		return ;
	}
	ft_list_move_insert(from_node, to, to_index, NULL);
	to->len++;
}
