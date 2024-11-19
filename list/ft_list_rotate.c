/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:26:19 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/19 10:07:32 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_list_rotate_right(t_list *list)
{
	if (list->len <= 1)
		return ;
	list->last->after = list->first;
	list->first = list->last;
	list->last = list->last->before;
	list->first->after->before = list->first;
}

void	ft_list_rotate_left(t_list *list)
{
	if (list->len <= 1)
		return ;
	list->first->before = list->last;
	list->last = list->first;
	list->first = list->first->after;
	list->last->before->after = list->last;
}
