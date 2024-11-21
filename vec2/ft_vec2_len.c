/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:21:28 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/21 19:54:05 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_vec2_square_len(t_vec2 vec)
{
	return (vec.x * vec.x + vec.y * vec.y);
}

float	ft_vec2_len(t_vec2 vec)
{
	return (sqrt(ft_vec2_square_len(vec)));
}

t_vec2	ft_vec2_normalize(t_vec2 vec)
{
	return (ft_vec2_divf(vec, ft_vec2_len(vec)));
}
