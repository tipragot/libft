/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2_op_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:21:28 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/21 19:52:25 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_vec2	ft_vec2_addf(t_vec2 a, float b)
{
	t_vec2	result;

	result.x = a.x + b;
	result.y = a.y + b;
	return (result);
}

t_vec2	ft_vec2_subf(t_vec2 a, float b)
{
	t_vec2	result;

	result.x = a.x - b;
	result.y = a.y - b;
	return (result);
}

t_vec2	ft_vec2_mulf(t_vec2 a, float b)
{
	t_vec2	result;

	result.x = a.x * b;
	result.y = a.y * b;
	return (result);
}

t_vec2	ft_vec2_divf(t_vec2 a, float b)
{
	t_vec2	result;

	result.x = a.x / b;
	result.y = a.y / b;
	return (result);
}
