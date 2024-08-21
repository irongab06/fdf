#include "../fdf.h"

void	ft_init_map(char *file, t_data *img)
{
	int		size;
	char	*str_map;
	char	**line;
	t_map	map;

	str_map = NULL;
	size = ft_size_map(file);
	str_map = ft_malloc(size);
	ft_bzero(str_map, (size_t)size);
	get_line_map(&str_map, file, size);
	line = ft_split(str_map, '\n');
	map = ft_split_colomn(line);
	map.column_count = ft_count_column(map.map);
	ft_malloc_init_map(&map);
	draw_map(&map, img);
	ft_free_3d(map.map);
	ft_free(&map);
	free(str_map);
	ft_free_str(line);
}