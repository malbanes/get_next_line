/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:29:47 by malbanes          #+#    #+#             */
/*   Updated: 2017/02/07 16:00:54 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 6

typedef struct	s_struct
{
	char	*tmp;
	char	*tmp2;
	char	buff[BUFF_SIZE + 1];
	int		ret;
    int     fin;
}				t_struct;

int				ft_strlen(char *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int i);
void			ft_putstr(char *s);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_memdel(void **ap);
char			*ft_strchr(const char *s, int c);
void			*ft_memalloc(size_t size);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strnew(size_t size);
int				get_next_line(const int fd, char **line);
int				cherche_char_c(char *s, char c);
int				retour_get_next_line(t_struct *get, char ***line, char **s);
void			ft_putchar(char c);

#endif
