/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_project.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:32:29 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/20 20:43:35 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_mat4	ft_mat_perspective(float fov, float aspect, float near, float far)
{
	t_mat4	result;

	result = ft_mat_identity();
	result.m[0][0] = 1.0 / (aspect * tanf(fov / 2.0));
	result.m[1][1] = 1.0 / tanf(fov / 2.0);
	result.m[2][2] = -(far / (far - near));
	result.m[2][3] = -(far * near) / (far - near);
	result.m[3][2] = 1.0;
	result.m[3][3] = 0.0;
	return (result);
}

t_mat4	ft_mat_ortho(float width, float height, float near, float far)
{
	t_mat4	result;

	result = ft_mat_identity();
	result.m[0][0] = 2.0 / width;
	result.m[1][1] = 2.0 / height;
	result.m[2][2] = 1.0 / (far - near);
	result.m[2][3] = -near / (far - near);
	return (result);
}
