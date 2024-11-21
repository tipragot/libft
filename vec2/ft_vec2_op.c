/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:21:28 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/21 19:52:12 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vec2	ft_vec2_add(t_vec2 a, t_vec2 b)
{
	t_vec2	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

t_vec2	ft_vec2_sub(t_vec2 a, t_vec2 b)
{
	t_vec2	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return (result);
}

t_vec2	ft_vec2_mul(t_vec2 a, t_vec2 b)
{
	t_vec2	result;

	result.x = a.x * b.x;
	result.y = a.y * b.y;
	return (result);
}

t_vec2	ft_vec2_div(t_vec2 a, t_vec2 b)
{
	t_vec2	result;

	result.x = a.x / b.x;
	result.y = a.y / b.y;
	return (result);
}
