/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:21:28 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/20 20:45:55 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

float	ft_vec3_square_len(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

float	ft_vec3_len(t_vec3 vec)
{
	return (sqrt(ft_vec3_square_len(vec)));
}

t_vec3	ft_vec3_normalize(t_vec3 vec)
{
	return (ft_vec3_divf(vec, ft_vec3_len(vec)));
}
