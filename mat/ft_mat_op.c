/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:32:29 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/20 20:41:49 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_mat4	ft_mat_translation(t_vec3 translation)
{
	t_mat4	result;

	result = ft_mat_identity();
	result.m[0][3] = translation.x;
	result.m[1][3] = translation.y;
	result.m[2][3] = translation.z;
	return (result);
}

t_mat4	ft_mat_rotation_x(float angle)
{
	t_mat4	result;

	result = ft_mat_identity();
	result.m[1][1] = cos(angle);
	result.m[1][2] = -sin(angle);
	result.m[2][1] = sin(angle);
	result.m[2][2] = cos(angle);
	return (result);
}

t_mat4	ft_mat_rotation_y(float angle)
{
	t_mat4	result;

	result = ft_mat_identity();
	result.m[0][0] = cos(angle);
	result.m[0][2] = sin(angle);
	result.m[2][0] = -sin(angle);
	result.m[2][2] = cos(angle);
	return (result);
}

t_mat4	ft_mat_rotation_z(float angle)
{
	t_mat4	result;

	result = ft_mat_identity();
	result.m[0][0] = cos(angle);
	result.m[0][1] = -sin(angle);
	result.m[1][0] = sin(angle);
	result.m[1][1] = cos(angle);
	return (result);
}

t_mat4	ft_mat_scale(t_vec3 scale)
{
	t_mat4	result;

	result = ft_mat_identity();
	result.m[0][0] = scale.x;
	result.m[1][1] = scale.y;
	result.m[2][2] = scale.z;
	return (result);
}
