/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:29:13 by malbanes          #+#    #+#             */
/*   Updated: 2017/01/09 16:02:42 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#define BUFF_SIZE 10

int		cherche_char_c(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{

	char		*buff;
	static char	*rest;
	int			ret;
	int			n;
	char		*tmp;

	if (!fd || fd < 1 || !line)
		return(-1);
	if (*line)
		free(*line);
	*line = ft_strnew(0);
	//ft_putendl("rest debut fct :");
	//ft_putendl(rest);
	if (rest != NULL)
	{
		n = cherche_char_c(rest, '\n');
		if (n == -1)
		{
			*line = ft_strjoin(*line, rest);
			//ft_putendl("line + rest :");
			//ft_putendl(*line);
		}
		else
		{
			//ft_putnbr(n);
			//ft_putendl("line debut :");
			*line = ft_strsub(rest, 0, n);
			//ft_putendl(*line);
			tmp = ft_strsub(rest, n + 1, ft_strlen(rest) - n + 1);
			ft_memdel((void*)&rest);
			rest = tmp;
		//	ft_putendl("rest2:");
			tmp = NULL;
		//	ft_putendl(rest);
		}
	}
	if (!rest || n == -1)
	{
		//ft_putendl("boucle while :");
		buff = ft_memalloc(BUFF_SIZE + 1);
		while ((ret = read(fd, buff, BUFF_SIZE) > 0 && cherche_char_c(buff, '\n') == -1))
		{
			ft_putnbr(ret);
			*line = ft_strjoin(*line, buff);
		}
		n = cherche_char_c(buff, '\n');
		//ft_putnbr(n);
		tmp = ft_memalloc(n + 1);
		tmp = ft_strncpy(tmp, buff, n);
		//ft_putstr("rest :");
		//ft_putendl(tmp);
		*line = ft_strjoin(*line, tmp);
		ft_memdel ((void*)&tmp);
		rest = ft_strsub(buff, n + 1, BUFF_SIZE - (n + 1));
		//ft_putendl(rest);
	}
	ft_memdel ((void*)&buff);
	ft_putendl(*line);
	return (1);
}

int		main(int ac, char **av)
{
	int	fd;
	char *str;

	str = (char*)malloc(sizeof(char) * 1);
	str[0] = '\0';
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("not open");
		return (0);
	}
	get_next_line(fd, &str);
	get_next_line(fd, &str);
	get_next_line(fd, &str);
	get_next_line(fd, &str);
	get_next_line(fd, &str);
	get_next_line(fd, &str);
	get_next_line(fd, &str);
	return (0);
}
