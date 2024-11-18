/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:25:50 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/18 20:34:12 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_list_clear(t_list *list)
{
	size_t	i;
	t_lnode	*temp;

	i = 0;
	while (i < list->len)
	{
		list->free_item(list->first->content);
		temp = list->first;
		list->first = temp->next;
		free(temp);
	}
	list->len = 0;
}
