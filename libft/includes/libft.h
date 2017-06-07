/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afourcad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:55:49 by afourcad          #+#    #+#             */
/*   Updated: 2017/06/07 18:53:42 by afourcad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <wchar.h>
# include <unistd.h>
# include <ctype.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**Fonction de travail sur la memoire.
*/

void				*ft_memalloc(size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				*ft_bzerocustom(void *s, size_t n, char c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memadd(void *dest, const void *src, int beg, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** Travail sur une chaine de caractere.
*/

char				*ft_strdup(const char *s);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_str_multi_free(char ***str);
void				ft_strfree(char **str);
void				ft_strdel(char **as);
char				**ft_strtab(int i, int j);
size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,
		size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2i, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_set_custom_tab(int x, int y, char c);
char				*ft_strndup(const char *s, size_t n);

/*
**Travail sur des nombres.
*/

long				ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
char				*ft_itoa(intmax_t n);
char				*ft_itoa_base(uintmax_t nbr, int base, char *abc);
char				*ft_uitoa(uintmax_t n);
int					ft_base_digitlen(uintmax_t nbr, int base);
int					ft_utf8_len(uintmax_t nbr);
uintmax_t			ft_abs(intmax_t nbr);
void				ft_quick_sort_tab(int *tab, int min, int max);

/*
** Affichage.
*/

void				ft_putendl(const char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_print_bit(int nb);

/*
** Liste chainees.
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem));

#endif
