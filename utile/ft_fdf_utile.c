#include "../fdf.h"

int	ft_size_map(char *file)
{
	int	fd;
	int	read_open;
	int	size;
	char buffer[1];

	size = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((read_open = read(fd, buffer, 1))> 0)
		size++;
	if (read_open < 0)
		return (0);
	close(fd);
	return (size);
}

char	*ft_malloc(int size)
{
	char	*str;

	if (size <= 0)
		return (NULL);
	str = NULL;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}

int	ft_strlen_map(char *str_map)
{
	int	i;

	i = 0;
	while (str_map[i])
	{
		i++;
	}
	return (i);
}

void	get_line_map(char **str_map, char *file, int size)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	while (ft_strlen_map(*str_map) < size)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = ft_strjoin(*str_map, line);
		if (temp == NULL)
        {
            free(line);
            break;
        }
		free(line);
		free(*str_map);
		*str_map = temp;
	}
	printf("str_map : %s\n", *str_map);
	close(fd);
}

t_map	ft_split_colomn(char **line)
{
	t_map	map;
	int		x;

	x = 0;
	map.line_count = ft_count_line(line);
	map.map = malloc(sizeof(char**) * (map.line_count + 1));
	while (line[x])
	{
		map.map[x] = ft_split(line[x], ' ');
		x++;
	}
	map.map[x] = NULL;
	return (map);
}