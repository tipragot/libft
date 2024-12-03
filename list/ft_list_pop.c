/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:05:13 by tcezard           #+#    #+#             */
/*   Updated: 2024/12/03 17:01:07 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_list_pop_first(t_list *list)
{
	t_lnode	*first_node;
	void	*content;

	if (list->len == 0)
		return (NULL);
	first_node = list->first;
	list->first = first_node->after;
	content = first_node->item;
	free(first_node);
	list->len--;
	return (content);
}

void	*ft_list_pop_last(t_list *list)
{
	t_lnode	*last_node;
	void	*content;

	if (list->len == 0)
		return (NULL);
	last_node = list->last;
	list->last = last_node->before;
	content = last_node->item;
	free(last_node);
	list->len--;
	return (content);
}

void	*ft_list_pop_at(t_list *list, size_t index)
{
	t_lnode	*node;
	void	*content;

	if (index >= list->len)
		return (NULL);
	else if (index == 0)
		return (ft_list_pop_first(list));
	else if (index == list->len - 1)
		return (ft_list_pop_last(list));
	node = ft_list_get_node(list, index);
	node->before->after = node->after;
	node->after->before = node->before;
	content = node->item;
	free(node);
	list->len--;
	return (content);
}
