/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:51:13 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/20 17:59:20 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_lnode	*ft_list_get_node(t_list *list, size_t index)
{
	size_t	i;
	t_lnode	*current;

	if (index >= list->len)
		return (NULL);
	i = 0;
	if (index <= list->len / 2)
	{
		current = list->first;
		while (i < index)
		{
			current = current->after;
			i++;
		}
	}
	else
	{
		index = list->len - index + 1;
		current = list->last;
		while (i++ < index)
			current = current->before;
	}
	return (current);
}

void	*ft_list_get(t_list *list, size_t index)
{
	t_lnode	*node;

	node = ft_list_get_node(list, index);
	if (node)
		return (node->item);
	return (NULL);
}

int	ft_list_contains(t_list *list, void *item)
{
	size_t	i;
	t_lnode	*current;

	i = 0;
	current = list->first;
	while (i < list->len)
	{
		if (current->item == item)
			return (1);
		current = current->after;
		i++;
	}
	return (0);
}
