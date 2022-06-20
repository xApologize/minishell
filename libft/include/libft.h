/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrossign <jrossign@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:11:07 by jrossign          #+#    #+#             */
/*   Updated: 2022/04/26 11:07:40 by jrossign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int character);
int		ft_isdigit(int character);
int		ft_isalnum(int character);
int		ft_isascii(int character);
int		ft_isprint(int character);
int		ft_toupper(int character);
int		ft_tolower(int character);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_atoi(const char *nptr);
int		ft_lstsize(t_list *lst);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstlen);
size_t	ft_strlcat(char *dest, const char *src, size_t dstlen);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*ft_strtrim(const char *s1, const char set);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	**ft_split(const char *s1, char c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, int len);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(char *str, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
#endif
