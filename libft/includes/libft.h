/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:14:13 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/05 17:09:17 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define BUF_SIZE	1024
# define RESET		"\e[0m"
# define BLUE		"\e[0;34m"
# define RED		"\e[0;31m"
# define YELLOW		"\e[0;33m"
# define GREEN		"\e[0;32m"
# define BACKRED	"\e[41m"
# define WHITE		"\e[4;37m"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_read
{
	int				fd;
	char			*content;
	struct s_read	*next;
}					t_read;

int					ft_atoi(char *str);
int					get_next_line(int const fd, char **line);
void				ft_bzero(void *s, size_t n);
t_list				*ft_create_elem(char *data);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **env, t_list *new);
void				ft_list_push_back(t_list **list, t_list *new);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar(char c);
int					ft_putchar_fd(char c, int fd);
void				ft_putchar_l(char c);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putlist(t_list *list);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcat(char *dest, char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(char const *s1, char const *s2);
char				*ft_strcpy(char *dest, char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
void				ft_strcolor(char *color, char *str);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strisdigit(char *str);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *c);
char				*ft_strndup(const char *s1, int count);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, int nb);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(char *str, char *to_find);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_swap(int a, int b);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif
