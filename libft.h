/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:03:17 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/18 10:25:01 by tcezard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lnode
{
	void			*content;
	struct s_lnode	*before;
	struct s_lnode	*next;
}					t_lnode;

typedef struct s_list
{
	size_t			len;
	t_lnode			*first;
	t_lnode			*last;
}					t_list;

int					ft_putchar(int fd, char c);
int					ft_putstr(int fd, char *str);
int					ft_putnbr(int fd, int n);
int					ft_putunbr(int fd, unsigned int n);
int					ft_puthex(int fd, unsigned long long n, int uppercase);
int					ft_putptr(int fd, void *ptr);
int					ft_printf_fd(const int fd, const char *format, ...);
int					ft_printf(const char *format, ...);

t_list				*ft_list_new(void);
void				ft_list_free(t_list *list, void (*free_content)(void *));
size_t				ft_list_len(t_list *list);
t_lnode				*ft_list_get_node(t_list *list, size_t index);
void				*ft_list_get(t_list *list, size_t index);
int					ft_list_push_first(t_list *list, void *content);
int					ft_list_push_last(t_list *list, void *content);
int					ft_list_push_at(t_list *list, size_t index, void *content);
void				*ft_list_pop_first(t_list *list);
void				*ft_list_pop_last(t_list *list);
void				*ft_list_pop_at(t_list *list, size_t index);
void				ft_list_rotate_right(t_list *list);
void				ft_list_rotate_left(t_list *list);
void				ft_list_iter(t_list *list, void (*visit)(void *));
void				ft_list_clear(t_list *list, void (*free_content)(void *));

#endif
