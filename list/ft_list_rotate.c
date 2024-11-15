/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_rotate_right.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:26:19 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/15 11:16:13 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_list_rotate_right(t_list *list)
{
	if (list->len <= 1)
		return ;
	list->last->next = list->first;
	list->first = list->last;
	list->last = list->last->before;
	list->first->next->before = list->first;
}

void	ft_list_rotate_left(t_list *list)
{
	if (list->len <= 1)
		return ;
	list->first->before = list->last;
	list->last = list->first;
	list->first = list->first->next;
	list->last->before->next = list->last;
}
