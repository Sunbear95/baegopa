/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyoo < jyoo@student.42gyeongsan.kr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:01:43 by jyoo              #+#    #+#             */
/*   Updated: 2025/05/08 21:49:31 by jyoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stdarg.h>
# define GNL_BUFFERSIZE 100

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int a);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *ptr, int value, size_t num);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *source, size_t num);
void		*ft_memmove(void *dest, const void *source, size_t num);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);

int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *string, int c);
char		*ft_strrchr(const char *string, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *ptr, int value, size_t num);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *str);

void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *src);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*dell)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void(*dell)(void *));

int			pt_putnbr_unsigned(unsigned int n);
int			pt_puthex(unsigned int n, char format);
int			pt_puthex_for_address(unsigned long long n);
int			pt_putpointer(void *ptr);
int			pt_process_format(va_list *args, char format);
int			ft_printf(const char *format, ...);
int			pt_putstr(char *str);
int			pt_putnbr(int nb);
int			pt_putchar(int c);
void		pt_arry_rev(char *str, int c);

char		*get_next_line(int fd);
ssize_t		chk_nl_eof(char *str, ssize_t flag);
char		*cut_n_paste(char *str, char **backup, ssize_t i_cut);
void		gnl_freeall(char **temp, char **backup);
char		*when_backup(char **backup);

char		*gnl_strdup(char *s1);
char		*gnl_strjoin(char **s1, char *s2);
size_t		gnl_strlen(char *s);
char		*gnl_substr(char *s, unsigned int start, size_t len);
size_t		gnl_strlcpy(char *dst, char *src, size_t size);

#endif
