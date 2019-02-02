/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyatsenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 11:43:15 by yyatsenk          #+#    #+#             */
/*   Updated: 2017/10/31 16:10:53 by yyatsenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "./libft.h"
# include <limits.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef enum		e_t
{
	none,
	s,
	S,
	p,
	d,
	D,
	i,
	o,
	O,
	u,
	U,
	x,
	X,
	c,
}					t_typer;

typedef enum		e_mode
{
	no,
	H,
	HH,
	L,
	LL,
	J,
	Z,
}					t_perech;

typedef struct		s_flag
{
	int nil;
	int minus;
	int plus;
	int space;
	int hash;
	int sign;
	int pres;
	int rozmir;
	int chlen;
}					t_flag;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,\
	size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa_l_l(long long int n);
char				*ft_itoa_l(long int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_strlen_num(int n);
int					ft_list_size(t_list *begin_list);
void				ft_whiteskip(char **str);
int					ft_num_of_words(char **arr);
size_t				ft_strlen_until_char(const char *str, char c);
char				*ft_itoa_base(unsigned int value, int base, int whatcase);
char				*ft_white_swap(char *str);
char				*ft_itoa_l_u(unsigned long int n);
char				*ft_itoa_l_l_u(unsigned long long n);
char				*ft_itoa_base_l(long value, int base, int whatcase);
char				*ft_itoa_base_l_u(unsigned long value, int base,\
	int whatcase);
char				*ft_itoa_base_l_l(long long value, int base, int whatcase);
char				*ft_itoa_base_u_l_l(unsigned long long value,\
	int base, int whatcase);
char				*ft_itoa_base_ssize(ssize_t value, int base, int whatcase);
char				*ft_itoa_long_ssize(ssize_t n);
char				*ft_itoa_short(short int n);
char				*ft_itoa_short_u(unsigned short int n);
char				*ft_itoa_base_u_short(unsigned short int value,\
	int base, int whatcase);
void				ft_putstr_null(char const *s);
wchar_t				*ft_wstrjoin(wchar_t *s1, wchar_t *s2);
wchar_t				*ft_wstrnew(size_t size);
wchar_t				*ft_wstrncpy(wchar_t *dst, wchar_t *src, size_t len);
wchar_t				*ft_white_swap_wstr(wchar_t *str, int wstrlen);
int					ft_wstrlen(wchar_t *wstr);
char				*ft_itoa_base_size(size_t value, int base, int whatcase);
int					ft_wcharlen(wchar_t wstr);
int					way_definder(char *format_line, va_list *ap, t_typer *type,\
	t_perech *data);
char				*flag_width_pres_maintain(char *format_line, char *str,\
	t_typer type);
char				*ft_modify(char *format, va_list *ap, t_perech *data,\
	t_typer type);
int					num_maintain(char *format_line, va_list *ap, t_typer *type,\
	t_perech *data);
char				*precision_num(char *format_line, char *str,\
	t_typer type, int *nil);
int					mod_norm_help(char *format, char **str, t_typer type,\
	int num);
char				*width_num(char *format_line, char *str,\
	char c, t_typer type);
char				*ft_white_swap_num(char *str, int space);
int					char_maintain_percent(char *format_line);
int					error_maintain(char *format_line);
char				*width_char(char *format_line, char *str, char c);
char				*flag_width_pres_maintain_char(char *format_line,\
	char *str);
int					write_wchar(wchar_t value);
int					ft_size_bin(long long int nb);
int					char_maintain(char *format_line, va_list *ap);
char				*width_ptr(char *format_line, char *str, char c);
char				*precision_ptr(char *format_line, char *str, int *prec);
int					ptr_maintain(char *format_line, va_list *ap);
char				*width_str(char *format_line, char *str, char c);
char				*precision_str(char *format_line, char *str, int *nil);
char				*flag_width_pres_maintain_str(char *format_line, char *str);
int					write_wstr(wchar_t *wstr);
wchar_t				*width_wstr(char *format_line, wchar_t *str, wchar_t c);
wchar_t				*precision_wstr(char *format_line, wchar_t *str,\
	int wstrlen, int *nil);
wchar_t				*flag_width_pres_maintain_wstr(char *format_line,\
	wchar_t *str, int wstrlen);
int					str_maintain(char *format_line, va_list *ap,\
	t_typer *type, t_perech *data);
char				*format_cat(char **format);
#endif
