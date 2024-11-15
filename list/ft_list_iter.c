/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:25:01 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/15 12:27:42 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_list_iter(t_list *list, void (*visit)(void *))
{
	size_t	i;
	t_lnode	*current;

	i = 0;
	current = list->first;
	while (i < list->len)
	{
		(*visit)(current->content);
		current = current->next;
		i++;
	}
}
