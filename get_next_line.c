/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:29:54 by malbanes          #+#    #+#             */
/*   Updated: 2017/04/10 20:35:30 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int		cherche_char_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		retour_get_next_line(t_struct *get, char ***line, char **s)
{
	if (ft_strlen(get->tmp) > 0)
	{
		**line = get->tmp;
		*s = NULL;
		return (1);
	}
	if (get->ret < 0)
		return (-1);
	free (**line);
//	free (*s);
	**line = NULL;
	free (get->tmp);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[1000000] = {NULL};
	static t_struct	get;

	get.fin = 3;
	if (fd < 0 || fd > 1000000 || !line || get.fin == 0)
		return (-1);
	*line = NULL;
	if (s[fd] == NULL)
		s[fd] = ft_memalloc(BUFF_SIZE + 1);
	get.tmp = ft_strncpy(ft_memalloc(BUFF_SIZE + 1), s[fd], BUFF_SIZE);
	while (ft_strchr(get.tmp, '\n') == NULL)
	{
		if ((get.ret = read(fd, get.buff, BUFF_SIZE)) < 1)
			return ((get.fin = retour_get_next_line(&get, &line, &s[fd])));
		get.buff[get.ret] = '\0';
		get.tmp2 = ft_strjoin(get.tmp, get.buff);
		free(get.tmp);
		get.tmp = get.tmp2;
	}
	*line = ft_strsub(get.tmp, 0,  cherche_char_c(get.tmp, '\n'));
	if (ft_strchr(get.tmp, '\n'))
		s[fd] = ft_strncpy(s[fd], ft_strchr(get.tmp, '\n') + 1,
				BUFF_SIZE + 1);
	free(get.tmp);

	return (1);
}
/*
int	main(int ac, char **av)
{
    int fd;
    char *str;

    fd = open(av[1], O_RDONLY);
    while (get_next_line(fd, &str) != 0)
	{
        ft_putendl(str);
		free(str);
	}
	ft_putendl("fin de lecture");
    while (1)
        fd = fd;
    return(0);
}*/
