/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:51:13 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/19 10:02:21 by tcezard          ###   ########.fr       */
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
		while (i < index)
		{
			current = current->before;
			i++;
		}
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
