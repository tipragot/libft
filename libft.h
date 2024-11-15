/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcezard <tcezard@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:03:17 by tcezard           #+#    #+#             */
/*   Updated: 2024/11/15 12:27:38 by tcezard          ###   ########.fr       */
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

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

int					ft_putchar(int fd, char c);
int					ft_putstr(int fd, char *str);
int					ft_putnbr(int fd, int n);
int					ft_putunbr(int fd, unsigned int n);
int					ft_puthex(int fd, unsigned long long n, int uppercase);
int					ft_putptr(int fd, void *ptr);

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
