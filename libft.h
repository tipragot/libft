/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:03:17 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/20 20:47:13 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <math.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_putchar(int fd, char c);
int					ft_putstr(int fd, char *str);
int					ft_putnbr(int fd, int n);
int					ft_putunbr(int fd, unsigned int n);
int					ft_puthex(int fd, unsigned long long n, int uppercase);
int					ft_putptr(int fd, void *ptr);
int					ft_printf_fd(const int fd, const char *format, ...);
int					ft_printf(const char *format, ...);

typedef struct s_lnode
{
	void			*item;
	struct s_lnode	*before;
	struct s_lnode	*after;
}					t_lnode;

typedef struct s_list
{
	size_t			len;
	t_lnode			*first;
	t_lnode			*last;
	void			(*free_item)(void *);
}					t_list;

t_list				ft_list_new(void (*free_item)(void *));
void				ft_list_clear(t_list *list);
size_t				ft_list_len(t_list *list);
t_lnode				*ft_list_get_node(t_list *list, size_t index);
void				*ft_list_get(t_list *list, size_t index);
int					ft_list_contains(t_list *list, void *item);
int					ft_list_push_first(t_list *list, void *item);
int					ft_list_push_last(t_list *list, void *item);
int					ft_list_push_at(t_list *list, size_t index, void *item);
void				*ft_list_pop_first(t_list *list);
void				*ft_list_pop_last(t_list *list);
void				*ft_list_pop_at(t_list *list, size_t index);
void				ft_list_rotate_right(t_list *list);
void				ft_list_rotate_left(t_list *list);
void				ft_list_iter(t_list *list, void (*visit)(void *));

typedef struct s_mat4
{
	float			m[4][4];
}					t_mat4;

typedef struct s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

t_mat4				ft_mat_identity(void);
t_mat4				ft_mat_perspective(float fov, float aspect, float near,
						float far);
t_mat4				ft_mat_ortho(float width, float height, float near,
						float far);
t_mat4				ft_mat_translation(t_vec3 translation);
t_mat4				ft_mat_rotation_x(float angle);
t_mat4				ft_mat_rotation_y(float angle);
t_mat4				ft_mat_rotation_z(float angle);
t_mat4				ft_mat_scale(t_vec3 scale);
t_mat4				ft_mat_mul(t_mat4 a, t_mat4 b);
t_vec3				ft_mat_apply(t_mat4 mat, t_vec3 vec);

t_vec3				ft_vec3_new(float x, float y, float z);
float				ft_vec3_square_len(t_vec3 vec);
float				ft_vec3_len(t_vec3 vec);
t_vec3				ft_vec3_normalize(t_vec3 vec);
t_vec3				ft_vec3_add(t_vec3 a, t_vec3 b);
t_vec3				ft_vec3_sub(t_vec3 a, t_vec3 b);
t_vec3				ft_vec3_mul(t_vec3 a, t_vec3 b);
t_vec3				ft_vec3_div(t_vec3 a, t_vec3 b);
t_vec3				ft_vec3_addf(t_vec3 a, float b);
t_vec3				ft_vec3_subf(t_vec3 a, float b);
t_vec3				ft_vec3_mulf(t_vec3 a, float b);
t_vec3				ft_vec3_divf(t_vec3 a, float b);

#endif
