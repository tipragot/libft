/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:32:29 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/20 20:44:31 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_mat4	ft_mat_identity(void)
{
	t_mat4	result;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.m[i][j] = i == j;
			j++;
		}
		i++;
	}
	return (result);
}

t_mat4	ft_mat_mul(t_mat4 a, t_mat4 b)
{
	t_mat4	result;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			result.m[i][j] = 0;
			while (k < 4)
			{
				result.m[i][j] += a.m[i][k] * b.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

t_vec3	ft_mat_apply(t_mat4 mat, t_vec3 vec)
{
	t_vec3	result;

	result.x = mat.m[0][0] * vec.x + mat.m[0][1] * vec.y + mat.m[0][2] * vec.z
		+ mat.m[0][3];
	result.y = mat.m[1][0] * vec.x + mat.m[1][1] * vec.y + mat.m[1][2] * vec.z
		+ mat.m[1][3];
	result.z = mat.m[2][0] * vec.x + mat.m[2][1] * vec.y + mat.m[2][2] * vec.z
		+ mat.m[2][3];
	return (result);
}
