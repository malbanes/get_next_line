#include "get_next_line.h"
#include <fcntl.h>
#define BUFF_SIZE 6

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

int     get_next_line(const int fd, char **line)
{
    char    *buff;
    int     ret;
    static char *linetmp = NULL;

    if (linetmp == NULL)
        linetmp = ft_memalloc(BUFF_SIZE + 1);
    if (fd < 1 || *line == NULL)
        return (-1);
    buff = ft_memalloc(BUFF_SIZE + 1);
    while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && ft_strchr(buff, '\n') == NULL)
    {
        buff[ret] = '\0';
        *line = ft_strjoin(*line, buff);
    }
    //linetmp = ft_strncpy()
    //*line = ft_strjoin(*line, linetmp);
    linetmp = ft_strcpy(linetmp, ft_strchr(buff, '\n'));
    ft_putstr(linetmp);
    return (0);
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
	//get_next_line(fd, &str);
	return (0);
}